#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    pair<int,int> event[] = {{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}}; //first = start,second = finish;
    int n = sizeof(event)/sizeof(event[0]);

    sort(event,event+n,[](pair<int,int> a,pair<int,int> b){
        return a.second < b.second;
    });

    int e=0,cnt=0;;
    for(int i=0 ; i<n ; i++){
        if(e<=event[i].first){
            e=event[i].second;
            cnt++;
        }
    }

    printf("%d",cnt);

    return 0;
}