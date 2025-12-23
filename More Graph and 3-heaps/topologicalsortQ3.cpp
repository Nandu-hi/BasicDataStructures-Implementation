#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int lbl;
    node(int a):lbl(a){}
};
class graph{
    public:
    int n;
    int m;
    vector<vector<node>> adj;
    vector<int> cid;
    graph(int a,int b){
        adj.resize(a);
        for(auto & it:adj){
            it={};
        }
        cid.resize(a);
        for(auto & it:cid){
            it=-1;
        }
        n=a;
        m=b;
    }
    void addedge(int a,int b){
        node temp1(b);
        adj[a].push_back(temp1);
    }
    vector<node> & getneighbours(int x){
        return adj[x];
    }

    void bfs(int a){
        queue<int> q;
        for(auto & it:cid){
            it=-1;
        }
        vector<int> visited(n,0);
        q.push(a);cid[a]=1;
        visited[a]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto it :getneighbours(x)){
                if(visited[it.lbl]==0){
                    q.push(it.lbl);
                    visited[it.lbl]=1;
                    cid[it.lbl]=1;
                }
            }
        }
        
    }

    void dfs(int a){
        vector<int> visited(n,0);
        dfs(a,visited);
    }

    void dfs(int a,vector<int> & visited){
        vector<node> nbr=getneighbours(a);
        cout << a << " ";
        visited[a]=1;
        for(auto it:nbr){
            if(!visited[it.lbl]) dfs(it.lbl,visited); 
        }
    }

    void check(){
        bool ans =true;
        for(auto it:cid){
            if(it!=1){
                ans=false;
            }
        }
        if(ans==true){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }

    void seq(){
        vector<int> indegree(n,0);
        queue<int> zin;
        vector<int> ans(n,0);
        int a=1;
        int visited=0;
        for(auto it:adj){
            for(auto y:it){
                indegree[y.lbl]++;
            }
        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                zin.push(i);
                visited++;
                ans[i]=1;
            }
        }

        while(!zin.empty() || visited<n){
            if(zin.empty()){
                cout << "Cycle" << endl;
                return;
            }
            int currsize=zin.size();
            for(int i=0;i<currsize;i++){
                int x=zin.front();
                zin.pop();
                if(ans[x]==0){
                    ans[x]=a;
                }
                for(auto it:getneighbours(x)){
                    indegree[it.lbl]--;
                    if(indegree[it.lbl]==0){
                        zin.push(it.lbl);
                        visited++;
                    }
                }
            }
            a++;
        }
        for(int i=0;i<n;i++){
            cout << i << " " << ans[i] << endl;
        }
    }

};
int main(){
    int n,m;
    cin >> n >> m;
    graph G(n,m);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        G.addedge(a,b);
    }
    G.seq();
}