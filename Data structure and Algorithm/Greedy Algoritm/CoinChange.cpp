#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int n; scanf("%d",&n);
    int n_coin = 0;

    n_coin+=n/1000;
    n%=1000;

    n_coin+=n/500;
    n%=500;

    n_coin+=n/100;
    n%=100;

    n_coin+=n/50;
    n%=50;

    n_coin+=n/20;
    n%=20;

    n_coin+=n/10;
    n%=10;

    n_coin+=n/5;
    n%=5;

    n_coin+=n/2;
    n%=2;

    n_coin+=n/1;
    n%=1;


    printf("%d",n_coin);
    return 0;
}