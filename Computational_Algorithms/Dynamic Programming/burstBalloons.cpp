/*
Problem:- ou are given n balloons, indexed from 0 to n – 1. Each balloon is painted with a number on it represented by an array. You are asked to burst all the balloons.

If you burst the ith balloon, you will get arr[i – 1] * arr[i] * arr[i + 1] coins. If i – 1 or i + 1 goes out of the array’s bounds, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.



Example: 

Input: N = 4, array[] = {3, 1, 5, 8}
Output: 167
Explanation:
First, we will burst the second balloon with 
the value 1. Coins = 3*1*5 = 15.
Second, we will burst the balloon with the 
value 5. Coins = 3*5*8 = 120.
Third, we will burst the balloon with the 
value 3. Coins = 1*3*8 = 24.
Fourth, we will burst the balloon with the 
value 8. Coins = 1*8*1 = 8.
So, the total number of coins we can collect 
is 167. This is the maximum number of coins we 
can collect.


Here we are discussing recursive approach

*/



#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Recursive function to calculate the maximum coins obtained
int maxCoinsHelper(int i, int j, vector<int> &nums) {
    if (i > j) return 0;
    int maxCoins = INT_MIN;
    
    // Iterate through each possible balloon to burst last
    for (int k = i; k <= j; k++) {
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        
        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = maxCoinsHelper(i, k - 1, nums) + maxCoinsHelper(k + 1, j, nums);
        
        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);
    }
    
    return maxCoins;
}

// Function to calculate the maximum coins obtained
int maxCoins(vector<int> &nums) {
    int n = nums.size();
    
    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // Call the helper function to compute the maximum coins
    return maxCoinsHelper(1, n, nums);
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    int maxCoinsResult = maxCoins(nums);
    cout << "Maximum coins obtained: " << maxCoinsResult << "\n";
    
    return 0;
}
