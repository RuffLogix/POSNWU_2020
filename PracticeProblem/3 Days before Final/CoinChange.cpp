#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    int coin_S[] = {1, 3, 5, 7};
    int n = sizeof(coin_S)/sizeof(coin_S[0]);
    int value = 18;

    int arr[value+1];
    for(int i=0 ; i<=value ; i++){
        arr[i] = 0x3f3f3f3f;
        for(int j=0 ; j<n ; j++){
            if(i==coin_S[j]){arr[i]=1;break;} 
            if(i>coin_S[j])arr[i] = min(arr[i-coin_S[j]]+1,arr[i]);
        }
    }

    cout << arr[value];

    return 0;
}