// an array will  be given to you which is not a heap

// heapify function is used to put the given node of bt to its correct position so it follows order of max heap

// for given array we know leaf node are from n/2+1 to n : hence those nodes are alrady a heap individually so we need to solve for 1 to n/2

// if we start indexing from 0 : left =2i+1 right = 2i+2

#include<iostream>
using namespace std;

void heapify(int *arr , int n, int i){
    int leftchild = 2*i;
    int rightchild = 2*i +1;
    int largest=i;

    if(leftchild<n && arr[leftchild]>arr[largest]){
        largest=leftchild;
    }
    else if(rightchild<n && arr[rightchild]>arr[largest]){
        largest=rightchild;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

int main(){
    int arr[6]={-1,54,55,53,52,50};
    int n=5;
    // build heap : O(n)
    // if arr started directly from 0th index the i =n/2 -1 where n=arr.size() as leaf node found at arr.size()/2 to arr.size()-1
    for(int i=n/2 ; i>0 ;i--){
        heapify(arr,n,i);
    }

    for(int i=1 ; i<=n ;i++){
        cout<<arr[i]<<" ";
    }
}