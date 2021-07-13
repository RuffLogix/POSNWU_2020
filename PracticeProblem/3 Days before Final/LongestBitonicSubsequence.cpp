#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int arr[] = {4, 2, 5, 9, 7, 6, 10, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int inc[n],dec[n];

    vector<int> v;
    for(int i=0 ; i<n ; i++){
        if(v.size()==0 || v.back()<arr[i])v.push_back(arr[i]);
        else {
            v[upper_bound(v.begin(),v.end(),arr[i])-v.begin()] = arr[i];
        }
        inc[i] = v.size();
    }

    v.clear() ; v.shrink_to_fit();
    for(int i=n-1 ; i>=0 ; i--){
        if(v.size()==0 || v.back()<arr[i])v.push_back(arr[i]);
        else {
            v[upper_bound(v.begin(),v.end(),arr[i])-v.begin()] = arr[i];
        }
        dec[i] = v.size();
    }

    int mx=0;
    for(int i=0 ; i<n ; i++){
        mx = max(mx,inc[i]+dec[i]-1);
    }

    cout << mx;
    return 0;
}