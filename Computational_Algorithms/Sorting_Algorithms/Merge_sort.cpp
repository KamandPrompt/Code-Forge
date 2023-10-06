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

// Merge Sort
// Time Complexity:  O(NlogN)
// Space Complexity: O(N)
void merge(vector<int> &arr,int s1=0, int e1=0, int s2=0, int e2=0){ // For mergesort
    int left_ptr=s1;
    int right_ptr=s2;
    int pos=0;
    vector<int> tempSort(e1+e2-s1-s2+2,0);
    while(left_ptr<=e1 && right_ptr<=e2){
        if(arr[left_ptr]<arr[right_ptr]){
            tempSort[pos++]=arr[left_ptr++];
        }
        else{
            tempSort[pos++]=arr[right_ptr++];
        }  
    }

    while(left_ptr<=e1){
        tempSort[pos++]=arr[left_ptr++]; 
    }
    while(right_ptr<=e2){
        tempSort[pos++]=arr[right_ptr++]; 
    }

    pos=0;
    for(int i=s1;i<=e2;i++){
        arr[i]=tempSort[pos++];
    }
    return;
}

void mergesort(vector<int> &arr,int s=0, int e=INT32_MIN){
    if(e==INT32_MIN) e=arr.size()-1;
    int n=e-s+1;
    if(n<=1){
        return;
    }
    mergesort(arr,s,s+n/2-1);
    mergesort(arr,s+n/2,e);
    merge(arr,s,s+n/2-1,s+n/2,e);
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

    mergesort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}