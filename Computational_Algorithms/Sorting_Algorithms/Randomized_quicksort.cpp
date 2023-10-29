#include<bits/stdc++.h>
using namespace std;

// Heapsort using cpp STL
void heapSort(int arr[],int low,int high){
    make_heap(arr+low,arr+high+1);
    sort_heap(arr+low,arr+high+1);
}

// Function to find random pivot element 
int partition(int arr[],int low,int high){
    int pivot=(rand()% (high-low+1)) +low;
    int pivot_element=arr[pivot];
    swap(arr[low],arr[pivot]);
    int l=low,r=high;
    while(l<r){
        while (arr[l]<=pivot_element) l++;
        while (arr[r]>pivot_element) r--;
        if (l<r) swap(arr[l],arr[r]);
    }
    arr[low]=arr[r];
    arr[r]=pivot_element;
    return r;
}

// Quicksort
void quickSort(int arr[],int low,int high,int mxD,int subP){
    if (high>low){
        if (mxD==0){
            // Calls HeapSort if threshold is reached
            heapSort(arr,low,high);
            return;
        }
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1,mxD-1,subP+1);
        quickSort(arr,pivot+1,high,mxD-1,subP+1);
    }
}

int main(){
    srand(time(0));
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++) cin>>arr[i];
    int mxD=2*log2(n),subP=0;
    quickSort(arr,0,n-1,mxD,subP);

    // Print sorted array
    for (int i=0;i<n;i++) cout<<arr[i]<< " ";
    cout<<endl;
    return 0;
}