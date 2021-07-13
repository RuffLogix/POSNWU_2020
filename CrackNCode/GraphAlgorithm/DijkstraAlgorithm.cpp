#include <bits/stdc++.h>

using namespace std;

int dijkstra(vector<pair<int,int>> adj[],int V,int src,int des){
	vector<bool> visited(V,false);
	vector<int> dist(V,0x3f3f3f3f);
	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;

	dist[src] = 0;
	q.push({dist[src],src});

	while(!q.empty()){
		int u = q.top().second; q.pop();

		visited[u] = true;

		for(auto x : adj[u]){
			int v=x.first , w=x.second;
			if(!visited[v] && dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				q.push({dist[v],v});
			}
		}
	}

	return dist[des];
}

int main(){
	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

	int V,E; scanf("%d %d",&V,&E);
	vector<pair<int,int>> adj[V+1];

	for(int i=0 ; i<E ; i++){
		int u,v,w; scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	int src,des; scanf("%d %d",&src,&des);
	printf("%d ",dijkstra(adj,V+1,src,des));

	return 0;
}

/*
4 5
1 2 2
1 4 8
2 3 2
2 4 4
3 4 1
1 4
*/