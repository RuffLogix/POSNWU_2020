//build : O(n) 
//query : O(1)
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=1 ; i<n ; i++){arr[i] += arr[i-1];}

    printf("%d",arr[4]-arr[2]);

    return 0;    
}