#include <bits/stdc++.h>

using namespace std;

#define graph vector<int>

void dfs(graph adj[],int V,int src){
    vector<bool> visited(V,false);
    stack<int> s;

    visited[src] = true;
    s.push(src);
    
    while(!s.empty()){
        int lastestElement = s.top(); s.pop();
        
        //Decresing order
        sort(adj[lastestElement].begin(),adj[lastestElement].end(),greater<int>());

        printf("%d ",lastestElement);

        for(auto x : adj[lastestElement]){
            if(!visited[x]){
                s.push(x);
                visited[x] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V,E; scanf("%d %d",&V,&E);
    int src; scanf("%d",&src);
    graph adj[V+1];

    for(int i=0 ; i<E ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(adj,V+1,src);

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