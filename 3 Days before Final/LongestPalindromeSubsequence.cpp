#include <bits/stdc++.h>

using namespace std;

int dp[101][101];

int solve(int l,int r,string s){
    if(l>r)return 0;
    if(dp[l][r] != 0)return dp[l][r];
    if(l==r)return dp[l][r] = 1;
    if(s[l]==s[r])return dp[l][r] = solve(l+1,r-1,s)+2;
    return dp[l][r] = max(solve(l,r-1,s) , solve(l+1,r,s));
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s = "ABBDCACB";
    
    cout << solve(0,s.size()-1,s);

    return 0;
}