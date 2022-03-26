#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(int *arr ,int s,int e){
    int mid = (s+e)/2;
    int l1 = mid - s +1;
    int l2 = e-mid;
    vector<int> v1(l1);
    vector<int> v2(l2);
    
    int k = s;
    for(int i = 0 ; i<l1;i++){
        v1[i] = arr[k++];
    }
    
    for(int i = 0 ; i<l2;i++){
        v2[i] = arr[k++];
    }
    int index1 = 0;
    int index2 = 0;
    k = s;

    while(index1 < l1 && index2 < l2) {
        if(v1[index1] < v2[index2]) {
            arr[k++] = v1[index1++];
        }
        else{
            arr[k++] = v2[index2++];
        }
    }   

    while(index1 < l1) {
        arr[k++] = v1[index1++];
    }

    while(index2 < l2 ) {
        arr[k++] = v2[index2++];
    }

}

void mergeSort(int *arr,int s,int e){

    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

int main()
{
    int arr[5] = {2,5,1,6,9};
    int n = 5;
    mergeSort(arr,0,n-1);
    for(auto x :arr){
        cout<<x<<" ";
    }
    return 0;
}