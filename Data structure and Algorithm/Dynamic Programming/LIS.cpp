#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v = {arr[0]};

    for(int i=1 ; i<n ; i++){
        if(arr[i]<v[0])v[0] = arr[i];
        else if(v.back()<arr[i])v.push_back(arr[i]);
        else {
            v[upper_bound(v.begin(),v.end(),arr[i])-v.begin()] = arr[i];
        }
    }

    cout << v.size();

    return 0;
}