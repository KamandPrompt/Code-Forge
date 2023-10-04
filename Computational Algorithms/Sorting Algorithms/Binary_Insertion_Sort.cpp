#include<iostream>
#include<vector>
using namespace std;

void print_array(vector<int> &arr){
    cout<<"Array: "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Binary Insertion Sort
// Time Complexity:  O(NlogN)
// Space Complexity: O(1)
int binarySearch(vector<int> &arr,int n, int key){
    int L = 0;
    int R = n;
    while(L < R){
        int mid = (L + R)/2;
        if (arr[mid] <= key) L = mid + 1;
        else R = mid;
    }
    return L;
}    

void BinaryInsertionSort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int key = arr[i];
        int pos = binarySearch(arr, i, key);
        int j = i;
        while(j > pos){
            arr[j] = arr[j-1];
            j--;
        }
        arr[pos] = key;
    }
}

int main(){
    // User Driven Function
    // int n;
    // cin>>n;
    
    // vector<int> arr(n);
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }

    // Using Saved Array
    vector<int> arr={4,2,5,1,6,7,3,7,23,62,3,1};

    cout<<"Original ";
    print_array(arr);

    BinaryInsertionSort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}