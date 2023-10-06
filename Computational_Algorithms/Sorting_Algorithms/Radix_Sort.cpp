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

// 7. Radix Sort
// Time Complexity:  O(D*(N + b)) - D= Number of digits, b= Base of number system 
// Space Complexity: O(N+b)
int getMax(vector<int> &arr){
    int maxi = INT32_MIN;
    for (int i=0;i<arr.size();i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

void countSort(vector<int> &arr, int exp){
    vector<int> output(arr.size());
    vector<int> counter(10,0);

    for (int i=0; i<arr.size();i++)
        counter[(abs(arr[i])/exp)%10]++;                // Freq

    for (int i=1;i<10;i++)
        counter[i]+=counter[i-1];                  // Cumulative Freq

    for (int i=arr.size()-1;i>=0;i--) {
        output[counter[(abs(arr[i])/exp)%10]-1]=arr[i]; // Put into correct position in stable manner
        counter[(abs(arr[i])/exp)%10]--;
    }

    arr=output;
    return;
}

void negativeSort(vector<int> &arr){
    vector<int> output;

    int negCounter=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=0){
            negCounter++;
            output.push_back(arr[i]);
        }
    }
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            output.push_back(arr[i]);
        }
    }   

    for(int i=0;i<negCounter/2;i++){
        swap(output[i],output[negCounter-i-1]);
    }

    arr=output;
    return;
}

void radixSort(vector<int> &arr){
    int maxi=getMax(arr);

    for (int exp=1; maxi/exp>0; exp*= 10){  // Solve digit wise
        countSort(arr, exp);
    }
    negativeSort(arr);
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

    radixSort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}