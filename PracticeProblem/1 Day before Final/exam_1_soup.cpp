#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);;

    int n; cin >> n;
    int arr[n];
    for(int i=0 ; i<n ; i++)cin >> arr[i];

    sort(arr,arr+n);

    int T; cin >> T;
    while(T--){
        int x; cin >> x;
        cout << lower_bound(arr,arr+n,x)-arr << '\n';
    }

    return 0;
}