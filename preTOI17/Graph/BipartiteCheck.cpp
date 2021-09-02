#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool solve(vector<int> adj[],int V){
    vector<bool> visited(V+1,false);
    vector<int> color(V+1,-1);

    stack<int> s;
    s.push(1);
    visited[1] = true;
    color[1] = 1;

    while(!s.empty()){
        int u=s.top(); s.pop();

        for(auto v : adj[u]){
            if(color[v]!=-1 && color[v]==color[u])return false;
            if(!visited[v]){
                visited[v] = true;
                color[v] = color[u]==1 ? 2 : 1;
                s.push(v);
            }
        }
    }

    return true;
}

int main(){

    int T; cin >> T;

    while(T--){
        int V,E; cin >> V >> E;
        vector<int> adj[V+1];

        for(int i=0 ; i<E ; i++){
            int u,v; cin >> u >> v;
            addEdge(adj,u,v);
        }

        if(solve(adj,V)){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }

    return 0;
}
/*
2 
4 4 
1 2 
2 3 
3 4 
4 1 
3 3 
1 2 
2 3 
3 1 
*/