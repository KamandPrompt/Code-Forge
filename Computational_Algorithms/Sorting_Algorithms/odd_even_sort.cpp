#include<bits/stdc++.h>
using namespace std;
void odd_even_sort(vector<int> &arr , int n){
    bool is_sorted = false;

    while (!is_sorted)
    {
    is_sorted = true;
for (int i = 0; i <= n-2; i = i+2)
{
    if(arr[i] >arr[i+1]){
        swap(arr[i],arr[i+1]);
        is_sorted = false;
    }
}
for (int i = 1; i <= n-2; i = i+2)
{
    if(arr[i] >arr[i+1]){
        swap(arr[i],arr[i+1]);
        is_sorted = false;
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