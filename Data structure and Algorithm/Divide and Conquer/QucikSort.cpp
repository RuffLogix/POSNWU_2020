#include <bits/stdc++.h>

using namespace std;

int getPivot(int arr[],int l,int r){
    int pivot = arr[r];
    int i = l-1;

    for(int j=l ; j<=r-1 ; ++j){
        if(arr[j]<=pivot){
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void solve(int arr[],int l,int r){
    if(l<r){
        int pivot = getPivot(arr,l,r);

        solve(arr,l,pivot-1);
        solve(arr,pivot+1,r);
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int arr[] = {5,3,1,9,15,1,12,2,7,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    solve(arr,0,n-1);

    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
