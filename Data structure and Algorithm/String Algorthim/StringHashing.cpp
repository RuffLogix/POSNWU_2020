#include <bits/stdc++.h>

using namespace std;

int hash_value(string s){
    int p = 31;
    int m = 1e9+7;
    int n = s.length();
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        s[i] = tolower(s[i]);
        sum += int((s[i]-'a'+1)*pow(p,i))%m;
    }

    return sum;
}

vector<string>  duplicate_string(vector<string> v){
    int n = v.size();
    pair<int,int> hash[n];
    for(int i=0 ; i<n ; i++){
        hash[i] = {hash_value(v[i]),i};
        //cout << hash[i].first << "\n";
    }

    sort(hash,hash+n);

    vector<string> result;
    for(int i=0 ; i<n ; i++){
        if(i!=0){
            if(hash[i].first!=hash[i-1].first)result.push_back(v[hash[i].second]);
        }else{
            result.push_back(v[hash[i].second]);
        }
    }

    return result;
}

int main(){
    vector<string> v = {"Aasdasd","BBasdas","Ca","DDDD","DDDD","EE","ACD","DEE","EE"};

    for (auto x : duplicate_string(v)){
        cout << x << "\n";
    }
    return 0;
}