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
        node temp(a);
        node temp1(b);
        adj[a].push_back(temp1);
        adj[b].push_back(temp);
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
};
int main(){
    int n;
    cin >> n;
    int edges;
    cin >> edges;
    int index;
    cin >> index;
    graph G(n,edges);
    for(int i=0;i<edges;i++){
        int a;
        int b;
        cin >> a>> b;
        G.addedge(a,b);
    }
    G.bfs(index);
    G.check();
}
