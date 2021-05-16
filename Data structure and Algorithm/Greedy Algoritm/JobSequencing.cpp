#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    pair<int,int> event[] = {{20,4},{10,1},{40,1},{30,1}};
    int n = sizeof(event)/sizeof(event[0]);

    sort(event,event+n,greater<pair<int,int>>());

    int profit=0;
    bool timeline[100]; //Static Memory
    memset(timeline,false,sizeof(timeline));

    for(int i=0 ; i<n ; i++){
        for(int j=event[i].second ; j>0 ; j--){
            if(!timeline[j]){
                timeline[j] = true;
                profit+=event[i].first;
                break;
            }
        }
    }

    printf("%d",profit);

    return 0;
}