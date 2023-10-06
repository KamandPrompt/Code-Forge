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


// Insertion Sort
// Time Complexity:  O(N2)
// Space Complexity: O(1)
void insertion_sort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int j=i-1;
        int key=arr[i];
        while((arr[j]>key) && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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

    insertion_sort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}