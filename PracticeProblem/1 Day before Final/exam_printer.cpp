#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    int T; cin >> T;
    list<string> ls;
    auto ptr = ls.begin();


    while(T--){
        char c; cin >> c;
        if(c=='l'){
            advance(ptr,-1);
        }else if(c=='r'){
            advance(ptr,1);
        }else if(c=='i'){
            string s; cin >> s;
            ls.insert(ptr,s);
        }else if(c=='b'){
            if(ptr!=ls.begin()){
                auto tmp = ptr;
                advance(tmp,-1);
                ls.erase(tmp);
            }
        }else if(c=='d'){
            if(ptr!=ls.end()){
                auto tmp = ptr;
                advance(ptr,-1);
                ls.erase(tmp);
                advance(ptr,1);
            }
        }
    }

    for(auto x : ls){
        cout << x << " ";
    }

    return 0;
}