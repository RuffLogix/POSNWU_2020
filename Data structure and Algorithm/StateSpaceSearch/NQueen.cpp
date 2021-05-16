#include <bits/stdc++.h>

using namespace std;

void solve(int x,int n,bool visited[],int arr[]){
    if(x==n){
        for(int i=0 ; i<n ; ++i)printf("%d ",arr[i]);printf("\n");
    }else{
        for(int i=0 ; i<n ; ++i){
            if(!visited[i]){
                bool skip = false;
                for(int j=0 ; j<x ; ++j){
                    if(abs(j-x)==abs(arr[j]-(i+1))){skip=true;break;}
                }
                if(skip)continue;
                visited[i]=true;
                arr[x]=i+1;
                solve(x+1,n,visited,arr);
                visited[i]=false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int n=4;
    bool visited[n];
    memset(visited,false,sizeof(visited));
    int arr[n];
    solve(0,n,visited,arr);

    return 0;
}