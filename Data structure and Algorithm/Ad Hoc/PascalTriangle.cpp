#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    for(int i=0 ; i<=n+1 ; i++){
        for(int j=1 ; j<=(n-i)*3+n+1 ; j++)cout << " ";
        int pre = 1;
        cout << setw(6) << pre << " ";
        for(int j=1 ; j<=i ; j++){
            pre = pre*(i+1-j)/j;
            cout << setw(6) << pre << " ";
        }
        cout << "\n";
    }
    return 0;
}