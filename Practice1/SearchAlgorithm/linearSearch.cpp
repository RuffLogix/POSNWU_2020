//O(n)

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 175;

    for(int i=0 ; i<n ; ++i){
        if(arr[i]==x){
            cout << i; 
            return 0;
        }
    }

    cout << "-1";

    return 0;
}