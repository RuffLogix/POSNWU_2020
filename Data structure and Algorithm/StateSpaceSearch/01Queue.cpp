#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 2;
    queue<vector<int>> q;
    q.push({0});
    q.push({1});

    while(!q.empty()){
        if(q.front().size()==n){
            for(auto x : q.front())cout << x << " ";
            cout << '\n';
        }else{
            vector<int> tmp = q.front();
            tmp.push_back(0);
            q.push(tmp);
            tmp.pop_back();
            tmp.push_back(1);
            q.push(tmp);
        }
        q.pop();
    }
    return 0;
}