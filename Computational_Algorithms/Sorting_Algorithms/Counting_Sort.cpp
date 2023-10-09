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

// Counting Sort
// Time Complexity:  O(N+K) K= Range of keys
// Space Complexity: O(Max(Ni))
void CountingSort(vector<int> &arr){
    int maxi=INT32_MIN;
    for(int i=0;i<arr.size();i++){
        maxi=max(maxi,arr[i]);
    }

    vector<int> output(arr.size());
    vector<int> counter(maxi+1,0);

    for (int i=0;i<arr.size();i++)
        counter[arr[i]]++;                // Freq

    for (int i=1;i<counter.size();i++)
        counter[i]+=counter[i-1];                  // Cumulative Freq

    for (int i=arr.size()-1;i>=0;i--) {
        output[counter[arr[i]]-1]=arr[i]; // Put into correct position in stable manner
        counter[arr[i]]--;
    }
    arr=output;
    return;
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

    CountingSort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}