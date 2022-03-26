#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(string s,string output,int index, vector<string> &ans){
        if(index>=s.length()){
            if(output.length()>0){
            ans.push_back(output);
            }
            return;
        }
        solve(s,output,index+1,ans);
        char temp = s[index];
        output.push_back(temp);
        solve(s,output,index+1,ans);
    }

int main()
{   string s = "abc";
    vector<string>ans;
    string output;
    int index = 0;
    solve(s,output,index,ans);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}