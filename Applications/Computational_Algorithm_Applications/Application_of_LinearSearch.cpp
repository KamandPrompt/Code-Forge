// application of linear search - finding first occurance of element

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
    int arr[] = {1, 1, 6, 3, 4, 3, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    int result = linearSearch(arr, n, key);

    if (result != -1) {
        cout << "First occurrence of " << key << " is at index " << result << endl;
    } else {
        cout << "Key " << key << " not found in the array" << endl;
    }

    return 0;
}


// other - last occurance
/*
int lastOccurrence(int arr[], int n, int key) {
    int lastIndex = -1; // Initialize with -1 to indicate key not found
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            lastIndex = i; // Update the index where the key is found
        }
    }
    
    return lastIndex;
}

int main() {
    int arr[] = {1, 1, 6, 3, 4, 3, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    int result = lastOccurrence(arr, n, key);

    if (result != -1) {
        cout << "Last occurrence of " << key << " is at index " << result << endl;
    } else {
        cout << "Key " << key << " not found in the array" << endl;
    }

    return 0;
}
*/