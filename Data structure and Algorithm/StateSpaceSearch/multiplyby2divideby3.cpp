#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int x=0;
    queue<pair<int,string>> q;
    q.push({1,"1"});

    while(!q.empty()){
        if(q.front().first==x){cout << q.front().second;break;}
        if(q.front().first!=0){
            q.push({q.front().first/3,q.front().second+"/3"});
            q.push({q.front().first*2,q.front().second+"*2"});
        }
        q.pop();
    }
    return 0;
}