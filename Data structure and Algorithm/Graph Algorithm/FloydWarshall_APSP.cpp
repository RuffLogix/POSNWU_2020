#include <bits/stdc++.h>

using namespace std;

int arr[101][101];

void AddEdge(int a,int b,int w){
    arr[a][b] = w;
    arr[b][a] = w;
}

void FloydWarshall(int V,int E){

    for(int k=0 ; k<V ; k++){
        for(int i=0 ; i<V ; i++){
            for(int j=0 ; j<V  ; j++){
                arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }

    for(int i=0 ; i<V ; i++){
        for(int j=0 ; j<V ; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int V=9,E=14;

    for(int i=0 ; i<V ; i++){
        for(int j=0 ; j<V ; j++){
            if(i!=j)arr[i][j] = 0x3f3f3f3f;
            else arr[i][j] = 0;
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

    FloydWarshall(V,E);
    return 0;
}