#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int a[n];

    pair<int,pair<int,int>> mx={-1e9,{0,0}};

    pair<int,pair<int,int>> mx_mx = mx;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        if(a[i]>mx.first+a[i]){
            mx.first = a[i];
            mx.second = {i,i};
        }else{
            mx.first += a[i];
            mx.second = {mx.second.first,i};
        }

        if(mx_mx.first < mx.first){
            mx_mx = mx;
        }
    }

    cout << mx_mx.second.first+1 << " " << mx_mx.second.second+1 << "\n" << mx_mx.first;
    return 0;
}

/*
LCS 
LIS 
Kadane 
01 Knapsac
Factorial
*/