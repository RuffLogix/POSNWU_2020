#include <bits/stdc++.h>

using namespace std;

map<int,vector<int> , greater<int>> m;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin >> n;

    for(int i=0 ; i<n ; i++){
        int a,b; cin >> a >> b;
        m[a].push_back(b);
    }

    for(auto x : m){
        cout << x.first << " ";
        for(auto y : x.second){
            cout << y << " ";
        }
        cout << "\n";
    }

    return 0;
}