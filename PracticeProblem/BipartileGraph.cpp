#include <bits/stdc++.h>

using namespace std;

int V,E;

bool solve(vector<int> adj[]){
    vector<int> color(V+1,-1);
    vector<bool> visited(V+1,false);
    stack<int> s;
    s.push(1);
    color[1] = 1;

    while(!s.empty()){
        int u = s.top() ; s.pop();
        visited[u] = true;

        for(auto x : adj[u]){
            if(visited[x])continue;

            if(color[u]==color[x])return false;

            if(color[u]==0)color[x] = 1;
            else color[x] = 0;
            
            s.push(x);
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin >> T;

    while(T--){
        cin >> V >> E;
        vector<int> adj[V+1];
        for(int i=0 ; i<E ; i++){
            int a,b; cin >> a >> b; 
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        if(solve(adj)){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }

    return 0;
}
/*
2
3 3
1 2
2 3 
3 1
4 3
1 2
1 3
4 1
*/