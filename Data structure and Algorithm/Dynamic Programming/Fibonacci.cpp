#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int N = 5;
    int fib[N+1];
    fib[0] = 0;
    fib[1] = 1;

    for(int i=2 ; i<=N ; i++){
        fib[i] = fib[i-1]+fib[i-2];   // Fib(n) = Fib(n-1)+Fib(n-2);
    }

    cout << fib[N];

    return 0;
}