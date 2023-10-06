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

// Cocktail Sort
// Time Complexity:  O(N2)
// Space Complexity: O(1)
void CocktailSort(vector<int> &arr){
    bool swapped=1;
    int start=0;
    int end=arr.size()-1;
 
    while(swapped){
        swapped=0;
        for(int i=start;i<end;++i) {
            if(arr[i]>arr[i+1]) {
                swap(arr[i], arr[i + 1]);
                swapped=1;
            }
        }
        if(!swapped) break;
 
        swapped=0;
        --end;
        for(int i=end-1;i>=start;--i) {
            if(arr[i]>arr[i+1]){
                swap(arr[i], arr[i+1]);
                swapped=1;
            }
        }
        ++start;
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

    CocktailSort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}