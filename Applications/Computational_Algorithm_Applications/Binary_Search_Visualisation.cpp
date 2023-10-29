#include <bits/stdc++.h>
using namespace std;
//Bianry search algorithm, is a very famous algorithm, which is used to searh for an element in a sorted array
//the array must be sorted either in ascending or the descendin order
//in this we keep reducing the search space into half till we don't find the target element
//if the element exist we returned the index of the element else we return -1 here;

int binarySearch(vector<int> & nums, int target){
    int low = 0; //initial pointer at the starting
    int high = nums.size()-1; //second pointer at the last element

    

    int count = 0;
    while(low <= high){ //we will keep iterating till one of the pointer crosses the second pointer
        cout << "*************************************" << endl;
        cout << count+1 <<" iteration"<< endl;
        count++;
        cout << "low is :" << nums[low] << endl;
        cout << "high is : "<< nums[high]<< endl;
        int mid = low + (high-low)/2;
        cout << "the mid indexed element is: " << nums[mid] << endl;

        if(nums[mid] == target) return mid; //if our mid indexed element is equal to the targer, then we simply return

        else if(nums[mid] < target) low = mid+1; //if the mid indexed element is lesser than target then we will search in the right half

        else high = mid-1; //if the mid-indexed element is larger than the target element then we will searh in the left half

    }
    return -1; //if the element is not found then we will return -1
}

int main()
{
 vector<int> nums{4, 10, 12, 16};

 //printing the initial array
 cout << "The given array is: ";
 for(auto i: nums){
    cout << i << " ";
 }
 cout << endl;
 int index = binarySearch(nums, 12);
 cout << "**************************************"<< endl;
 if(index == -1) cout << "Element doesnot exist in the array"<< endl;
 else cout << "The target element exist at index "<< index << endl;
 
 return 0;
}