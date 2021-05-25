#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int a,int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void dfs(vector<int> adj[],int V,int src){
    vector<bool> visited(V,false);
    stack<int> s;

    visited[src] = true;
    s.push(src);

    while(!s.empty()){
        int t = s.top(); s.pop();
        cout << t << " ";

        for(auto x : adj[t]){
            if(!visited[x]){
                s.push(x);
                visited[x] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int V=5;

    vector<int> adj[V];

    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,4);
    addEdge(adj,1,3);
    addEdge(adj,4,3);
    addEdge(adj,1,2);
    addEdge(adj,3,2);

    dfs(adj,V,0);

    return 0;
}