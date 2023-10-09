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

// Quick Sort
// Time Complexity:  Average(NlogN), Worst(N2)
// Space Complexity: O(logN)
int quick(vector<int> &arr,int s,int e){  // For quicksort
    int pivot=s;
    int j=pivot+1;
    for(int i=s+1;i<=e;i++){
        if(arr[i] <= arr[pivot]){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    swap(arr[pivot],arr[j-1]);
    pivot=j-1;
    return pivot;
}

void quicksort(vector<int> &arr,int s=0, int e=INT32_MIN){
    cout<<s<<" "<<e<<endl;
    if(e==INT32_MIN) e=arr.size()-1;
    int n=e-s+1;
    if(n<=1){
        return;
    }
    int pivot=quick(arr,s,e);
    quicksort(arr,s,s+pivot-1);
    quicksort(arr,s+pivot+1,e);
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

    quicksort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}