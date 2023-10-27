//Searching Algorithm - Linear Search

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
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

    int result=linearSearch(arr,n,key);

    if (result != -1) {
        cout <<"key found at "<< result<<endl;
    } else {
        cout <<"key not found"<<endl;
    }
    return 0;
}