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
    bool check(){
        bool ans =true;
        for(auto it:cid){
            if(it!=1){
                return false;
            }
        }
    
        return true;
    }

    void twoconn(){
        vector<pair<int,int>> ans;
        int time=0;
        vector<int> arrival(n);
        vector<int> depart(n);
        vector<int> visited(n);
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                parent[i]=-1;
                twoconn(i,time,ans,arrival,depart,visited,parent);
            }
        }
        if(ans.size()==0){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
            for(auto it:ans){
                cout << it.first << " " << it.second << endl;
            }
        }
    }

    int twoconn(int k,int & time,vector<pair<int,int>> & ans,vector<int> & arrival,vector<int> & depart,vector<int> & visited,vector<int> & parent){
        visited[k]++;
        arrival[k]=time++;
        int deepest=arrival[k];
        vector<node> nbr=getneighbours(k);
        for(int i=0;i<nbr.size();i++){
            if(nbr[i].lbl==parent[k]) continue;
            int deep;
            if(visited[nbr[i].lbl]){
                deep = arrival[nbr[i].lbl];
            }
            else{
                parent[nbr[i].lbl]=k;
                deep=twoconn(nbr[i].lbl,time,ans,arrival,depart,visited,parent);
            }
            deepest=min(deep,deepest);
        }
        depart[k]=time++;
        if(parent[k]!=-1 && arrival[k]==deepest){
            ans.push_back({k,parent[k]});
        }
        return deepest;
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
    G.bfs(0);
    if(!G.check()){
        cout << "Graph is not connected \nChecking individual components\n";
    }
    G.twoconn();
}