#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {0,3,5,8,9,10,17,17,20};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=1 ; i<n ; i++){
        for(int j=1 ; j< i ; j++){
            arr[i] = max(arr[i],arr[j]+arr[i-j]);
        }

        cout << arr[i] << " ";
    }
    return 0;
}