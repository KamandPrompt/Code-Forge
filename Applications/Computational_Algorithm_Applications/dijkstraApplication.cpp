/*
Dijkstra is a very interesting algorithm that can give us the shortest path reach a certain position.
Here, we will be considering an example which will be indicating the implemention of Dijkstra's algorithm.
The example is as stated:
**Cheapest Flights Within K Stops
We have n cities and m edges which are connected by some number of flights. 
1. We have flights array which contains element in the form [fromi, toi, price[i]] i.e we have the subarray in which we have the
information that we have to go from a given city to another city and the price that is costed by moving from a given city to another city.
2. We also have three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
3. If we don't find such route, then we can return -1 which signify that we don't have any route that can satisfy all our conditions.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        /* we are given the flights so to solve it using Dijkstra's algorithm we have to make an adjacency list to do the further
         procedure.*/
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        /* Now we will create a queue which stores the node and their distances from the 
        source in the form of {stops, {node, dist}} with ‘stops’ indicating 
        the number of nodes between src and current node.*/
        queue<pair<int, pair<int, int>>> q;
        
        q.push({0, {src, 0}});

        // Here we are storing the updated distance from our calculations in the code given below.
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // We first iterate through the graph using a queue like in Dijkstra with popping out the element with min stops first.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // We stop the process when we the min number of steps we are given.
            if (stops > K)
                continue;
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;

                // We only update the queue if the new calculated dist is
                //less than the prev and the stops are also within limits.
                if (cost + edW < dist[adjNode] && stops <= K)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }
       // if after our calculations we still have dist[dist] = 1e9 then we return -1 it signify we can't reach that destination with our
       // given conditions
        if (dist[dst] == 1e9)
            return -1;
        // otherwise we return the dist[dst] that is the min cost we have to pay to reach from one city to another with min k stops
        return dist[dst];
    }
};


int main() {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    return 0;
}
