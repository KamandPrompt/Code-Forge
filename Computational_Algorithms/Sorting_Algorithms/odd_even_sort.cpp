#include<bits/stdc++.h>
using namespace std;
void odd_even_sort(vector<int> &arr , int n){
    bool is_sorted = false;  //initialised a flag to track if array is sorted or not.
    
    while (!is_sorted)
    {
    is_sorted = true; //make flag as sorted initially
for (int i = 0; i <= n-2; i = i+2) //loop over even elements
{
    if(arr[i] >arr[i+1]){
        swap(arr[i],arr[i+1]); //if next element is smaller than swap the elements 
        is_sorted = false;//mark the flag as unsorted as we have swapped the elements
    }
}
for (int i = 1; i <= n-2; i = i+2) //loops over odd elements
{
    if(arr[i] >arr[i+1]){
        swap(arr[i],arr[i+1]);//if next element is smaller than swap the elements 
        is_sorted = false; //mark the flag as unsorted as we have swapped the elements
    }
}
    }
}
int main()
{
    vector<int> arr ={5 ,2 ,6 ,78 ,8};
    odd_even_sort(arr , arr.size());
    for(auto ele : arr){
        cout<<ele<<endl;
    }
    return 0;
}