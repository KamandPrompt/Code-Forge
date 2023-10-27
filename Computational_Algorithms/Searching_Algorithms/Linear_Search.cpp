//Searching Algorithm - Linear Search

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) { // iterating through the array
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 6;

    int result=linearSearch(arr,n,key); //linearly searches through the array for the given element i.e key 

    if (result != -1) {
        cout <<"key found at "<< result<<endl; // if the given element is there, it prints out the result
    } else {
        cout <<"key not found"<<endl;
    }
    return 0;
}
// Linear search is a simple searching algorithm that iterates through a list or array of elements in a sequential manner. 
// It checks each element one by one until the target value is found or the end of the list is reached.
// Space Complexity: O(1)
// Time Complexity: O(n)
