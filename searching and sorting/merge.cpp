#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(vector<int> &ar,int ini,int m,int f){
    vector<int> ar1;
    vector<int> ar2;
    int n1 = m-ini+1;
    int n2 = f-m;
     int temp;
    for (int i = 0; i < n1; i++)
    {    temp = ar[ini+i];
         ar1.push_back(temp);
    }
    for (int i = 0; i < n2; i++)
    {    temp = ar[m+i+1];
         ar2.push_back(temp);
    }

    int i = 0,j=0,k=ini;
    while(i<n1 and j<n2){
        if(ar1[i]>ar2[j]){
            ar[k] = ar1[i];
            i++;
        }else{
            ar[k]=ar2[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        ar[k]=ar1[i];
        k++;
        i++;
    }
    while(j<n2){
        ar[k]=ar2[j];
        k++;
        j++;
    }
    
}

void mergesort(vector<int> &ar,int i , int f){

   if(i>=f){
       return;
   }
   int mid = i + (f-i)/2;
    mergesort(ar,i,mid);
    mergesort(ar,mid+1,f);
    merge(ar,i,mid,f);

}

int main(){
    vector<int> ar;
    ar.push_back(6);
    ar.push_back(8);
    ar.push_back(1);
    ar.push_back(9);
    ar.push_back(10);
    ar.push_back(0);

    mergesort(ar,0,ar.size()-1);
    for (auto x:ar)
    {
        cout<<x<<" ";
    }
    
    return 0;
}

/*
Time complexity of Merge Sort is  θ(nLogn) in all 3 cases (worst, average and best)
as merge sort always divides the array into two halves and takes linear time to merge two halves.

Space complexity is O(N)

its Stable

Merge sort is more useful in case of linked list
Unlike an array, in the linked list, we can insert items in the middle in O(1) extra space and O(1) time.
Therefore, the merge operation of merge sort can be implemented without extra space for linked lists.
*/