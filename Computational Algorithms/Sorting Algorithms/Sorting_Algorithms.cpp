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

void print_array(vector<float> &arr){
    cout<<"Array: "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// 1. Selection Sort
// Time Complexity:  O(N2)
// Space Complexity: O(1)
void selection_sort(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++){
        int min_index=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}

// 2. Bubble Sort
// Time Complexity:  O(N2)
// Space Complexity: O(1)
void bubble_sort(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++){
        bool swapped=0;
        for(int j=0;j<arr.size()-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
}

// 3. Insertion Sort
// Time Complexity:  O(N2)
// Space Complexity: O(1)
void insertion_sort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int j=i-1;
        int key=arr[i];
        while((arr[j]>key) && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void insertion_sort(vector<float> &arr){ // Over ride for floats
    for(int i=1;i<arr.size();i++){
        int j=i-1;
        int key=arr[i];
        while((arr[j]>key) && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

// 4. Merge Sort
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

// 5. Quick Sort
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

// 8. Counting Sort
// Time Complexity:  O(N+K) K= Range of keys
// Space Complexity: O(Max(Ni))
void CountingSort(vector<int> &arr){
    int maxi=INT32_MIN;
    for(int i=0;i<arr.size();i++){
        maxi=max(maxi,arr[i]);
    }

    vector<int> output(arr.size());
    vector<int> counter(maxi+1,0);

    for (int i=0;i<arr.size();i++)
        counter[arr[i]]++;                // Freq

    for (int i=1;i<counter.size();i++)
        counter[i]+=counter[i-1];                  // Cumulative Freq

    for (int i=arr.size()-1;i>=0;i--) {
        output[counter[arr[i]]-1]=arr[i]; // Put into correct position in stable manner
        counter[arr[i]]--;
    }
    arr=output;
    return;
}

// 9. Bogo Sort
// Time Complexity:  O(infinity)
// Space Complexity: O(1)
bool isSorted(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        if (arr[i] < arr[i - 1])
            return false;
        }    
    return true;
}

void shuffle(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        swap(arr[i], arr[rand() % arr.size()]);
    }
}
 
void Bogosort(vector<int> &arr){
    while (!isSorted(arr))
        shuffle(arr);
}

// 10. Binary Insertion Sort
// Time Complexity:  O(NlogN)
// Space Complexity: O(1)
int binarySearch(vector<int> &arr,int n, int key){
    int L = 0;
    int R = n;
    while(L < R){
        int mid = (L + R)/2;
        if (arr[mid] <= key) L = mid + 1;
        else R = mid;
    }
    return L;
}    

void BinaryInsertionSort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int key = arr[i];
        int pos = binarySearch(arr, i, key);
        int j = i;
        while(j > pos){
            arr[j] = arr[j-1];
            j--;
        }
        arr[pos] = key;
    }
}

// 11. Bucket Sort
// Time Complexity:  O(N+K) K= Number of buckets
// Space Complexity: O(K)
void BucketSort(vector<int> &arr){
  int maxi = INT32_MIN;
  for(int i=0;i<arr.size();i++){
    maxi=max(maxi,arr[i]);
  }  
  vector<int> bucket(maxi,0);
  for (int i=0;i<arr.size();i++){  
    bucket[arr[i]]++;  
  }  
  for(int i=0,j=0;i<=maxi;i++){  
    while(bucket[i]>0){  
      arr[j++]=i;
      bucket[i]--;  
    }  
  }  
}  

// 12. Cocktail Sort
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

// 13. Tim Sort (Used by Python)
// Time Complexity:  O(NlogN)
// Space Complexity: O(N)
void insertionSort(vector<int> &arr, int left, int right){
    for (int i=left+1;i<=right;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=left && arr[j]>temp) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void merge(int arr[], int l, int m, int r){
    // Merge function merges the sorted runs
    // Original array is broken in two parts left and right array
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    // After comparing, we merge those two array in larger sub array
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left, if any
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }

    // Copy remaining element of right, if any
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void TimSort(vector<int> &arr){

    // Sort individual subarrays of size RUN
    int RUN=32;
    int n=arr.size();
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, min((i + RUN - 1), (n - 1)));

    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = RUN; size < n; size = 2 * size) {

        // pick starting point of
        // left sub array. We
        // are going to merge
        // arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we
        // increase left by 2*size
        for (int left = 0; left < n; left += 2 * size) {

            // Find ending point of
            // left sub array
            // mid+1 is starting point
            // of right sub array
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

// 14. Comb Sort
// Time Complexity:  O(N2)
// Space Complexity: O(1)
int getNextGap(int gap){
    gap = (gap*10)/13;
    if (gap < 1)
        return 1;
    return gap;
}
 
void CombSort(vector<int> &arr){
    // Initialize gap
    int n=arr.size();
    int gap = n;
 
    // Initialize swapped as true to make sure that loop runs
    bool swapped = true;
 
    // Keep running while gap is more than 1 and last iteration caused a swap
    while (gap != 1 || swapped == true){
        // Find next gap
        gap = getNextGap(gap);
 
        // Initialize swapped as false so that we can check if swap happened or not
        swapped = 0;
 
        // Compare all elements with current gap
        for (int i=0; i<n-gap; i++){
            if (arr[i] > arr[i+gap]){
                swap(arr[i], arr[i+gap]);
                swapped = 1;
            }
        }
    }
}

// 15. Shell Sort
// Time Complexity:  O(N2)
// Space Complexity: O(1)
int ShellSort(vector<int> &arr){
    int n=arr.size();
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2){
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1){
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
  
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
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

    ShellSort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}