#include <bits/stdc++.h>
using namespace std;

//Prim's Algorith: This algorithm is used to find the minimum Spanning tree of a graph
//Spanning Tree: A tree in which we have N nodes and N-1 edges and all the nodes are reachable from each other
//Minimum spanning tree: Spanning tree of A graph which has the minimum sum of weights of edges
//here we will print the weight of the minimum spanning tree

//Intuition: it is a Greedy Approach: as each time we are choosing teh minimum weight graph

int SpannigTree(int v, vector<vector<int>> adj[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; //this is used to choose the minimum weight edge, since topmost element of the priority queue is minimum of all the elements

    vector<int> vis(v, 0); //this is the visited array
    //{wt, node}
    pq.push({0, 0}); // as taking starting node 0, with weight 0
    int sum = 0;
    cout << "The elements in the queue are:" << endl;
    int count = 0;
    while(!pq.empty()){
        cout << "---------------------------------------"<< endl;
        cout << count+1<< " iteration" <<endl;
        count++;
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first; //weight of the node
        cout << "the node is: "<< node << endl;
        cout << "the weight is: " << wt << endl;
        if(vis[node] == 1) continue;
        //add to the mst
        vis[node] = 1;
        sum += wt;
        for(auto it: adj[node]){
            int adjNode = it[0];//adjacent node
            int edW = it[1]; //i.e edge weight
            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;



}

int main()
{
    vector<vector<int>> adj[] = {{{1, 2}, {3, 6}}, {{0, 2}, {2, 3}, {4, 5}, {3, 8}}, {{1, 3}, {4, 7}}, {{0, 6}, {1, 8}}, {{1, 5}, {2, 7}}};
    //printing the adcency list of the graph
    cout << "******************************************************"<< endl;
    cout << "Prim's Algorithm visualisation"<< endl;
    cout << "******************************************************"<< endl;
    int n = sizeof(adj)/sizeof(adj[0]);
    cout << "printing the adjacecy list with {node, weight}"<<endl;
    for(int i = 0; i< n; i++){
        cout <<"For the node:"<< i << ":";
        for(auto j: adj[i]){
            int adjNode = j[0];
            int edgeW = j[1];
            cout << "{"<< adjNode <<", "<< edgeW<< "}, ";

            
        }
        cout << endl;
    }
    cout << "******************************************************"<< endl;
    int ans = SpannigTree(5, adj);
    cout << "The sum of the Minimum Spanning Tree is: "<<ans<< endl;
    cout << "******************************************************"<< endl;

 return 0;
}