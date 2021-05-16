#include <bits/stdc++.h>

using namespace std;

int cnt=0;

void solve(int sum,int x,int arr[],int n,int des){
    if(sum==des){cnt++;return ;}
    if(x==n || sum>des)return;

    solve(sum+arr[x],x+1,arr,n,des);
    solve(sum,x+1,arr,n,des);
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int n=6;
    int arr[] = {3,34,4,12,5,2};
    int x=9;

    solve(0,0,arr,n,x);

    printf("%d",cnt);
    return 0;
}