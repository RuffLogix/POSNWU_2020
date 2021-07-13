//Counting Connected Component
#include <bits/stdc++.h>

using namespace std;

#define graph vector<int>
#define MAX_V 1000
vector<bool> visited(MAX_V,false);

void floodfill(graph adj[],int src){
    stack<int> s;

    s.push(src);
    visited[src] = true;

    while(!s.empty()){
        int lastestElement = s.top(); s.pop();

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

    int V,E ; scanf("%d %d", &V, &E);
    int src ; scanf("%d" , &src);
    graph adj[V+1];

    for(int i=0 ; i<E ; i++){
        int u,v ; scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans=0;
    for(int i=1 ; i<=V ; i++){
        if(!visited[i]){
            ++ans;
            floodfill(adj,i);
        }
    }

    printf("%d",ans);

    return 0;
}

/*
8 8 1
1 2
1 6
2 3
2 4
4 3
5 1
5 4
7 8
*/