#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int quicky(vector<int>& nums,int start,int end){
        int pivot = nums[start];
        int count=0;
        for(int i=start+1;i<=end;i++){
            if(nums[i]<=pivot){
                count++;
            }
        }
        int pivotindex=count+start;
        swap(nums[pivotindex],nums[start]);
        int i = start;
        int j = end;
        while(i<pivotindex and j>pivotindex){
           while(nums[i]<=pivot){
                i++;
            }
            
            while(nums[j]>pivot){
                j--;
            }
            
            if(i<pivotindex and j>pivotindex){
                swap(nums[i++],nums[j--]);
            }
        }
        return pivotindex;
    }
    
    void sort(vector<int>& nums,int start,int end){
        if(start>=end){
            return;
        }
        swap(nums[start + rand() % (end - start + 1)], nums[start]);
        int pivot = quicky(nums, start, end);
        sort(nums,start, pivot-1);
        sort(nums,pivot+1, end);
    }

int main(){
    vector<int> ar;
    ar.push_back(6);
    ar.push_back(8);
    ar.push_back(1);
    ar.push_back(9);
    ar.push_back(10);
    ar.push_back(0);

    sort(ar,0,ar.size()-1);
    for (auto x:ar)
    {
        cout<<x<<" ";
    }
    
    return 0;
}

/*
The worst case occurs when the partition process always picks greatest or smallest element as pivot
The best case occurs when the partition process always picks the middle element as pivot
Quick sort is not stable
its inplace
*/