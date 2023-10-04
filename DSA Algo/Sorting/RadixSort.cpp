#include <iostream>
using namespace std;

// gets maximum elements in the array
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// counting sort in the array passed through radix sort algorithms
void countSort(int arr[], int n, int exp)
{

    int output[n];
    int i, count[10] = { 0 };  // an array of length 10 to count the number of each digit in a particular position
                               // for example, ones, tens etc.

    for (i = 0; i < n; i++)    //updating the count array
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)    // cumulating the count at each position
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {           // sorting the array based on count array
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];    // the element is inputted into the output array based on the value in count array.
        count[(arr[i] / exp) % 10]--;        // updating the count based on output.
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)        // a simple function that repeats the counting sort for every significant digit of the input
{  
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)   // the loop is executed as many times as the number of significant digits in maximum
        countSort(arr, n, exp);
}

int main(){
    int n;
    cin >> n;
    int x[n];

    for(int i = 0; i < n; i++ ){          // input the array
        cin >> x[i];
    }

    
    radixsort(x, n);
    cout << "Sorted List:" << endl;
    for (int i = 0; i<n ; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    return 0;
}