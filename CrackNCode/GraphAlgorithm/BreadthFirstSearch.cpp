#include <bits/stdc++.h>

using namespace std;

#define graph vector<int>

void bfs(graph adj[],int V,int src){
    vector<int> visited(V,false);
    queue<int> q;

    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int frontestElement = q.front(); q.pop();

        printf("%d ",frontestElement);

        for(auto x : adj[frontestElement]){
            if(!visited[x]){
                q.push(x);
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
        int u,v; scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(adj,V+1,src);

    return 0;
}

/*
12 11 1
1 2
1 3
1 4
2 5
2 6
4 7
4 8
5 9
5 10
7 11
7 12
*/