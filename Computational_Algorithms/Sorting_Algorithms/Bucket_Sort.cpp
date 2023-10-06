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

// Bucket Sort
// Time Complexity:  O(N+K) K= Number of buckets
// Space Complexity: O(K)
void BucketSort(vector<int> &arr){
  int maxi = INT32_MIN;
  for(int i=0;i<arr.size();i++){
    maxi=max(maxi,arr[i]);
  }  
  vector<int> bucket(maxi,0);
  for (int i=0;i<arr.size();i++){  
    bucket[arr[i]]++;  
  }  
  for(int i=0,j=0;i<=maxi;i++){  
    while(bucket[i]>0){  
      arr[j++]=i;
      bucket[i]--;  
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

    BucketSort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}