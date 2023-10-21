/*
Dijkstra’s Algorithm is a method for finding the shortest path between nodes in an undirected graph.
Algorithm Steps:-
A. Using Priority Queue
Question:- Why use priority queue? Becuase we always want minimum dist at first. 
1. Create a distance array and initialize all the elements of distance array as infinite or a very big number except the source node.
2. Create a priority queue in which we will storing the {dist, node}.
3. Now store the source node with dist equal zero in the priority queue.
4. Now iterate through the priority queue till it becomes empty and store the dist and node in variables named dis and node respectively andd pop the element 
from the priority queue.
5. Now iterate through adjacent element of the node as adjnode and edgeweight to reach from node to adjnode if the 
edgeweight+ dis(dist to reach the node) is less than the dist[adjnode] update the dist[adjnode] and push {dist[adjnode],adjnode} in the 
priority queue.
6. Return the distance array.

B. Using Set
Why set? Because it stores unique elements and the smallest element at the top(Stores element in ascending order). 
** Set has the liberty to erase the elements so if the element is already visited at a distance greater than the dis+edgeweight then 
the set can directly erase that elemnt and node from the set that will save the further iterations which was not possible in priority queue.
Algorithm steps:-
Similar to that we have in priority queue 1 extra step is added to erase the pair if the distance stored in the array is greater than the 
distance that we find by ierating. 

Time Complexity: O(Elog(V)), where E is the number of edges and V is the number of nodes.
Space Complexity: O(|E|+|V|), where E is the number of edges and V is the number of nodes.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //  using priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i =0;i<V;i++){
            dist[i] = 1e9;
        }
        // now make the distance of the source equal to zero
        dist[S] = 0;
        pq.push({0, S});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int edgeweight = it[1];
                int adjnode = it[0];
                if(dis+edgeweight<dist[adjnode]){
                    dist[adjnode] = dis+edgeweight;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
// using set
        set<pair<int,int>> st; 

        // Initialising dist list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> dist1(V, 1e9); 
        
        st.insert({0, S}); 

        // Source initialised with dist=0
        dist1[S] = 0;
        
        // Now, erase the minimum distance node first from the set
        // and traverse for all its adjacent nodes.
        while(!st.empty()) {
            auto it = *(st.begin()); 
            int node = it.second; 
            int dis = it.first; 
            st.erase(it); 
            
            // Check for all adjacent nodes of the erased
            // element whether the prev dist is larger than current or not.
            for(auto it : adj[node]) {
                int adjNode = it[0]; 
                int edgW = it[1]; 
                
                if(dis + edgW < dist[adjNode]) {
                    // erase if it was visited previously at 
                    // a greater sist.
                    if(dist1[adjNode] != 1e9) 
                        st.erase({dist1[adjNode], adjNode}); 
                        
                    // If current distance is smaller,
                    // push it into the queue
                    dist1[adjNode] = dis + edgW; 
                    st.insert({dist1[adjNode], adjNode}); 
                 }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return dist1; 

    }
};





int main()
{
    
    int V, E, S;
    cout << "Enter the number of vertices (V): ";
    cin >> V;
    cout << "Enter the number of edges (E): ";
    cin >> E;
    cout << "Enter the source vertex (S): ";
    cin >> S;

    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cout << "Enter edge (u v w): ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // Add the reverse edge for an undirected graph
    }

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    cout << "Shortest distances from source vertex " << S << " to all other vertices: " << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << res[i] << endl;
    }
    return 0;
}
/*
Contributed by:- 
Simran
B21224
*/


