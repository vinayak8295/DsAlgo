#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool driver(string q){
    int counter=0;
            for(int i = 0 ; i<q.size()-1;i++){
                if(q[i]=='.')
                 counter++;
                 if(q[i]==q[i+1] and q[i]=='.')
                 return 0;
            }
            if(q[q.size()-1]=='.' or q[0] == '.' or counter!=3)
            return 0;
        int temp=0;
        bool zero = false;
        for(auto x : q){
            if(x=='.'){
             if(temp>=0 and temp<=255){
                 temp = 0;
                 zero = false;
                 
             }else{
                 return 0;
             }
            }else
            if(x>=48 and x<=57){
                if(zero){
                    return 0;
                }
                if(x==48 and temp==0){
                    zero = true;
                }
                temp = temp*10 + (x-'0');
            }else{
                return 0;
            }
        }
            return 1;
}

int main(){
    string s = "";
    cout<<driver(s);
    return 0;
}