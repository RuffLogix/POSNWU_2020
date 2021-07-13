#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price)/sizeof(price[0]);
    int x = 8;

    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=i ; j++){
            price[i] = max(price[i],price[i-j]+price[j]);
        }
    }

    cout << price[x];

    return 0;
}