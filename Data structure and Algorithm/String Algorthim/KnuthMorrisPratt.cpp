#include <bits/stdc++.h>

using namespace std;

vector<int> compute_prefix(string t){
    vector<int> pi(t.size());
    int k=0;

    for(int q=1 ; q<t.size() ; q++){
        while(k>0 && t[k]!=t[q]){
            k = pi[k-1];
        }
        if(t[k]==t[q])k++;
        pi[q] = k;
    }
    return pi;
}

void KMP(string s,string t){
    int n = s.size(),m = t.size();
    vector<int> pi = compute_prefix(t);
    int q=0;

    for(int i=0 ; i<n ; i++){
        while(q>0 && s[i]!=t[q]){
            q = pi[q-1];
        }
        if(t[q]==s[i])q++;
        if(q==m){
            cout << i-m+1 << " ";
            q = pi[q-1];
        }
    }
}

int main(){
    string s1="asvxasaabaaabdasdavaabaaabdadaaabaaab";
    string s2="aabaaab";

    KMP(s1,s2);
    return 0;
}
