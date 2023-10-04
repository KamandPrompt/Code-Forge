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

// Comb Sort
// Time Complexity:  O(N2)
// Space Complexity: O(1)
int getNextGap(int gap){
    gap = (gap*10)/13;
    if (gap < 1)
        return 1;
    return gap;
}
 
void CombSort(vector<int> &arr){
    // Initialize gap
    int n=arr.size();
    int gap = n;
 
    // Initialize swapped as true to make sure that loop runs
    bool swapped = true;
 
    // Keep running while gap is more than 1 and last iteration caused a swap
    while (gap != 1 || swapped == true){
        // Find next gap
        gap = getNextGap(gap);
 
        // Initialize swapped as false so that we can check if swap happened or not
        swapped = 0;
 
        // Compare all elements with current gap
        for (int i=0; i<n-gap; i++){
            if (arr[i] > arr[i+gap]){
                swap(arr[i], arr[i+gap]);
                swapped = 1;
            }
        }
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

    CombSort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}