#include <bits/stdc++.h>

using namespace std;

int getPriority(char a){
    if(a=='^')return 4;
    if(a=='*' || a=='/')return 3;
    if(a=='+' || a=='-')return 2;
    if(a=='(')return 1;
    return -1;
}

int main(){
    string str = "a+b*(c^d-e)^(f+g*h)-i";
    stack<char> s;

    string ans="";
    for(int i=0 ; i<str.length() ; ++i){
        if(str[i]>='a' && str[i]<='z'){
            ans+=str[i];
        }else if(str[i]=='('){
            s.push(str[i]);
        }else if(str[i]==')'){
            while(!s.empty() && s.top()!='('){
                ans+=s.top();
                s.pop();
            }
            s.pop();
        }else{
            while(!s.empty() && getPriority(str[i])<=getPriority(s.top())){
                ans+=s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }

    cout << ans;

    return 0;
}