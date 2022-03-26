#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/*
0 0 0 1 2
A B C A B
0 1 2 3 4
*/

void compute_lps(string pattern, vector<int> &ar){
    int n = pattern.length();
    int len=0;
    int i = 1;
    while (i<n)
    {
         if(pattern[i]==pattern[len]){
             len++;
             ar[i]=len;
             i++;
         }else{
             if(len!=0){
                 len = ar[len-1];

             }else{
                 ar[i]=0;
                 i++;
             }
         }
    }
       
}

bool kmp(string text,string pattern){

    vector<int> lps_array(pattern.size(),0);
    compute_lps(pattern,lps_array);
    int i=0,j=0;
    while(i<text.size()){
        if(pattern[j]==text[i]){
            i++;
            j++;
        }
        if(j==pattern.size()){
            return 1;
        }
        else if (i < text.size() && pattern[j] != text[i]) {
        
            if (j != 0)
                j = lps_array[j - 1];
            else
                i = i + 1;
        }
    }
    return 0;


}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    cout<<kmp(text,pattern)<<endl;
    return 0;
}
