/*
You are given an array/list ‘ARR’ consisting of ‘N’ non-negative integers. You are also given a list ‘QUERIES’ consisting of ‘M’ queries, where the ‘i-th’ query is a list/array of two non-negative integers ‘Xi’, ‘Ai’, i.e ‘QUERIES[i]’ = [‘Xi’, ‘Ai’].

The answer to the ith query, i.e ‘QUERIES[i]’ is the maximum bitwise xor value of ‘Xi’ with any integer less than or equal to ‘Ai’ in ‘ARR’.

You should return an array/list consisting of ‘N’ integers where the ‘i-th’ integer is the answer of ‘QUERIES[i]’.



*/

/*
Explanation

Example 1:
Input:

2
5 2
0 1 2 3 4
1 3
5 6
1 1
1
1 0  

Output:
3 7
-1

Explanation:
In the first test case, the answer of query [1, 3] is 3 because 1^2 = 3 and 2 <= 3,  and the answer of query [5, 6] is 7 because  5 ^ 2 = 7 and 2 <= 6.

In the second test case, no element is less than or equal to 0 in the given array ‘ARR’.


*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

vector < int > maxXorQueries(vector < int > & arr, vector < vector 
< int >> & queries) {
  int n = arr.size();
  int m = queries.size();
  vector < int > ans(m, -1);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[j] <= queries[i][1]) {
        ans[i] = max(ans[i], arr[j] ^ queries[i][0]);
      }
    }
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector < int > arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector < vector < int >> queries;

    for (int i = 0; i < m; i++) {
      vector < int > temp;
      int xi, ai;
      cin >> xi >> ai;
      temp.push_back(xi);
      temp.push_back(ai);
      queries.push_back(temp);
    }

    vector < int > ans = maxXorQueries(arr, queries);
    for (int j = 0; j < ans.size(); j++) {
      cout << ans[j] << " ";
    }
    cout << endl;
  }

}