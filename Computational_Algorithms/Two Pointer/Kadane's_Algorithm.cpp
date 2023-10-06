/*KADANE'S ALGORITHM for finding maximum possible contiguous subarray sum*/

/*Algorithm
    1)initialize an integer(let's say int sum) with minimum value(INT_MIN)
    2)inititalize an integer(let's say int current) with value 0
    3)iterate over an array(int a[])
    4)update current=max(a[i],a[i]+current)
    4)if (current>=sum) update sum, make it equal to current
    5)if (current<sum) do nothing
*/

#include<bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int> nums) {

    int ans=INT_MIN;
    int cur=0;
    for(int num:nums){
        cur=max(num,cur+num);
        if(cur>=ans){
            ans=cur;
        }
        else{
            continue;
        }
    }
    return ans;
}

/*TWO POINTER APPROACH comes in play when we want to find the length of max subarray*/
/*  just initialize 3 more integers to save start & end indexes as 0
    update end whenever sum increases
    update start whenever sum decreases
}
*/
int main(){
    vector<int>a;
    int n;
    cin>>n;//size of array
    for (int i = 0; i < n; i++)
    {
        int k;
        cin>>k;
        a.push_back(k);
    }
    
    int ans=maxSubArray(a);
    cout<<ans;
}


