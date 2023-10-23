/*
Problem:- 
A subsequence of an array is a list of elements of the array where some elements are deleted ( or not deleted at all) and they should be in the same order in the subsequence as in the original array.

For example, for the array: [2,3,1] , the subsequences will be [{2},{3},{1},{2,3},{2,1},{3,1},{2,3,1}} but {3,2} is not a subsequence because its elements are not in the same order as the original array.

What is the Longest Increasing Subsequence?

The longest increasing subsequence is described as a subsequence of an array where:

All elements of the subsequence are in increasing order.
This subsequence itself is of the longest length possible.


Example:-

Arr[]={10,9,2,5,3,7,101,18};
Longest Increasing Subsequence:-  {2,3,7,101}
                                        or
                                    {2,3,7,18}
The length of longest increasing subsequence is 4 



*/


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function to find the length of the longest increasing subsequence
int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>>& dp) {
    // Base condition
    if (ind == n)
        return 0;
        
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    
    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
    
    int take = 0;
    
    if (prev_index == -1 || arr[ind] > arr[prev_index]) {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }
    
    return dp[ind][prev_index + 1] = max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n) {
    // Create a 2D DP array initialized to -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
    return getAns(arr, n, 0, -1, dp);
}

int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence(arr, n);
    
    return 0;
}