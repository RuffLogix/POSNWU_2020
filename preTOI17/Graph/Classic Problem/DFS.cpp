#include <bits/stdc++.h>

using namespace std;

void DFS(int u,vector<int> adj[],bool visited[]){
    cout << u+1 << " ";
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v])DFS(v,adj,visited);
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V,E,src; cin >> V >> E >> src; --src;
    vector<int> adj[V];

    for(int i=0 ; i<E ; i++){
        int u,v; cin >> u >> v; --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool visited[V];
    memset(visited,false,sizeof(visited));
    DFS(src,adj,visited);

    return 0;
}
/*
12 11 1
1 2
1 7
1 8
2 3
2 6
3 4
3 5
8 9
8 12
9 10
9 11
*/