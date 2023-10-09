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

// 6. Heap Sort
// Time Complexity:  O(NlogN)
// Space Complexity: O(1)
void heapify(int* arr,int n,int i){// For Heapsort
    int leftIndex=i*2;
    int rightIndex=i*2+1;
    
    if(leftIndex>n){
        return;
    }

    if(arr[i]<arr[leftIndex]){
        if(rightIndex<=n && arr[leftIndex]<arr[rightIndex]){
            swap(arr[i],arr[rightIndex]);
            heapify(arr,n,rightIndex);
            return;
        }
        swap(arr[i],arr[leftIndex]);
        heapify(arr,n,leftIndex);
    }

    else if(rightIndex<=n && arr[i]<arr[rightIndex]){
        swap(arr[i],arr[rightIndex]);
        heapify(arr,n,rightIndex);
    }
    else return;
    
}

void make_heap(int* arr,int n){ // For Heapsort
    if(n<=1){
        return;
    }
    int index=n/2;

    for(int i=index;i>0;i--){
        heapify(arr,n,i);
    }
}

void heapsort(vector<int> &data){
    int n = data.size();
    int* arr=new int[n+1];
    arr[0]=-1;
    
    for(int i=0;i<n;i++){
        arr[i+1]=data[i];
    }
    
    make_heap(arr,n);
    
    for(int j=0;j<n;j++){
        swap(arr[1],arr[n-j]);
        heapify(arr,n-j-1,1);
    }
    for(int i=0;i<n;i++){
        data[i]=arr[i+1];
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

    heapsort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}