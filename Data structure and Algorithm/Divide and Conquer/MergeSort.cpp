#include <bits/stdc++.h>

using namespace std;

void solve(int arr[],int l,int r){
    if(l==r)return;
    int m = (l+r)/2;

    solve(arr,l,m);
    solve(arr,m+1,r);

    int a_l[(m-l)+1],a_r[r-(m+1)+1];

    for(int i=l ; i<=m ; i++)a_l[i-l] = arr[i];
    for(int i=m+1 ; i<=r ; i++)a_r[i-(m+1)] = arr[i];

    int idx_l=0,idx_r=0,idx_c=l;
    while(idx_l!=(m-l)+1 and idx_r!=r-(m+1)+1 and idx_c<=r){
        if(a_l[idx_l]<=a_r[idx_r]){
            arr[idx_c] = a_l[idx_l++];
        }else{
            arr[idx_c] = a_r[idx_r++];
        }
        idx_c++;
    }

    while(idx_l!=(m-l)+1 and idx_c<=r){
        arr[idx_c++] = a_l[idx_l++];
    }

    while(idx_r!=r-(m+1)+1 and idx_c<=r){
        arr[idx_c++] = a_r[idx_r++];
    }
}

int main(){
    int arr[] = {5,3,1,9,15,1,12,2,7,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    solve(arr,0,n-1);

    for(auto x : arr){
        cout << x << " ";
    }
    return 0;
}