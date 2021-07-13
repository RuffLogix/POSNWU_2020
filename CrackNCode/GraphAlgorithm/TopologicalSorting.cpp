#include <bits/stdc++.h>

using namespace std;

#define graph vector<int>

#define MAX_V 1000
vector<bool> visited(MAX_V,false);
stack<int> s;

void topological(graph adj[],int i){
    visited[i] = true;

    for(auto x : adj[i]){
        if(!visited[x]){
            topological(adj,x);
        }
    }

    s.push(i);
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V,E; scanf("%d %d", &V, &E);
    graph adj[V+1];

    for(int i=0 ; i<E ; i++){
        int u,v; scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }

    for(int i=1 ; i<=V ; i++){
        if(!visited[i]){
            topological(adj,i);
        }
    }

    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }


    return 0;
}

/*
8 9
1 4 
1 5
2 4
3 5
3 8
4 6
4 7
4 8
5 7
*/