#include <bits/stdc++.h>

using namespace std;

void solve(int l,int r,int arr[]){
    if(l==r)return;

    int m = (l+r)/2;

    solve(l,m,arr); solve(m+1,r,arr);

    int arr1[m-l+1],arr2[r-m];
    for(int i=0 ; i<m-l+1 ; i++){arr1[i] = arr[i+l];}
    for(int i=0 ; i<r-m ; i++){arr2[i] = arr[m+i+1];}

    int ll=0,rr=0,i=l;
    while(i<=r && ll<=m-l && rr<r-m){
        if(arr1[ll]<arr2[rr]){
            arr[i]=arr1[ll++];
        }else{
            arr[i]=arr2[rr++];
        }
        i++;
    }

    while(ll<=m-l){
        arr[i++]=arr1[ll++];
    }
    while(rr<r-m){
        arr[i++]=arr2[rr++];
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int arr[]  = {5 , 1 , 2 , 4 ,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    solve(0,n-1,arr);

    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}