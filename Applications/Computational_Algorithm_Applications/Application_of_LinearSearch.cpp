// application of linear search - finding first occurace of element
/*
Finding the first occurrence using linear search refers to the process of locating the initial occurrence of a specific element in a list, array, or data structure by sequentially examining each element from the beginning until a match is found.
For example, if you have an array [3, 1, 4, 1, 5, 9, 2, 6] and you're searching for the first occurrence of 1, the linear search would stop at index 1 and return 1 as the first occurrence.
*/

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


// similarly other application can also be - last occurance of an element
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