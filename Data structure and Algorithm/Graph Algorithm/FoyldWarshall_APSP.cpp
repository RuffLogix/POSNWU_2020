#include <bits/stdc++.h>

using namespace std;

int adj[9][9];

void AddEdge(int a,int b,int w){
    adj[a][b] = w;
    adj[b][a] = w;
}

void foyldwarshall(int V){
    for(int k=0 ; k<V ; k++){
        for(int i=0 ; i<V ; i++){
            for(int j=0 ; j<V ; j++){
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }

    for(int i=0 ; i<V ; i++){
        cout << adj[i][0] << " ";
    }
}

int main(){
    int V=9,E=14;

    for(int i=0 ; i<V ; i++){
        for(int j=0 ; j<V ; j++){
            if(i==j)adj[i][j] = 0;
            else adj[i][j] = 1e9;
        }
    }


    AddEdge(0,1,4);
    AddEdge(0,7,8);
    AddEdge(1,7,11);
    AddEdge(1,2,8);
    AddEdge(7,8,7);
    AddEdge(7,6,1);
    AddEdge(8,6,6);
    AddEdge(2,8,2);
    AddEdge(2,3,7);
    AddEdge(2,5,4);
    AddEdge(6,5,2);
    AddEdge(3,5,14);
    AddEdge(3,4,9);
    AddEdge(5,4,10);

    foyldwarshall(V);

    return 0;
}

