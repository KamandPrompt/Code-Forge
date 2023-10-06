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

// Selection Sort
// Time Complexity:  O(N2)
// Space Complexity: O(1)
void selection_sort(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++){
        int min_index=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
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

    selection_sort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}