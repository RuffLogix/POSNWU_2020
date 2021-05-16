#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int N = 8;
    int coin[N+1];
    coin[0] = 0;
    coin[1] = coin[3] = coin[4] = 1;
    coin[2] = 2;

    for(int i=5 ; i<=N ; i++){
        coin[i] = min(coin[i-1],min(coin[i-3],coin[i-4]))+1;
    }

    cout << coin[N];

    return 0;
}

