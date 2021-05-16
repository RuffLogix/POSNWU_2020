#include <bits/stdc++.h>

using namespace std;

void RabinKarp(string s,string t){
    int p = 31;
    int m = 1e9+7;
    int S = s.size(), T = t.size();

    vector<int> pow(max(S,T)+1);
    pow[0] = 1;
    for(int i=1 ; i<=max(S,T) ; i++)pow[i] = (pow[i-1]*p)%m;

    vector<int> hs(S+1);
    hs[0] = 0;
    for(int i=1 ; i<=S ; i++)hs[i] = (hs[i-1]+(s[i-1]-'A'+1)*pow[i-1])%m;
    int ht=0;
    for(int i=1 ; i<=T ; i++)ht = (ht+(s[i-1]-'A'+1)*pow[i-1])%m;

    for(int i=0 ; i<S-T+1 ; i++){
        int curr = (hs[i+T]-hs[i]+m)%m;
        if(curr==(ht*pow[i])%m){
            cout << i << " ";
        }
    }
}

int main(){
    string s,t;
    s = "ABCABDEFABG";
    t = "AB";
    RabinKarp(s,t);
}
