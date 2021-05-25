#include <bits/stdc++.h>

using namespace std;

int visited[1000010];
stack<int> s;
void topological(vector<int> adj[],int x){
    visited[x] = true;
    for(auto i : adj[x]){
        if(!visited[i])topological(adj,i);
    }

    s.push(x);
}

void topological_util(vector<int> adj[],int V){
    for(int i=0 ; i<V ; i++){
        if(!visited[i]){
            topological(adj,i);
        }
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V=8;
    vector<int> adj[V];

    adj[0].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[1].push_back(3);
    adj[3].push_back(6);
    adj[4].push_back(7);
    adj[5].push_back(7);
    topological_util(adj,V);

    return 0;
}


