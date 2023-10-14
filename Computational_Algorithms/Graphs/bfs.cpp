#include <bits/stdc++.h>
#include <set>
#include <queue>
#include <list>
using namespace std;
// This C++ program is designed to perform Breadth-First Search (BFS) on an undirected graph.
//  BFS is a graph traversal algorithm that explores all the vertices of the graph in breadth-first order
//  starting from a given source vertex.

// In terms of time complexity, constructing the adjacency list takes O(E) time, where E is the number of edges.
// The BFS traversal, in the worst case, has a time complexity of O(V + E), where V is the number of vertices and E is the number of edges.
// The overall time complexity of the BFS algorithm in this code is O(V + E).

// This code can be useful for exploring and analyzing undirected graphs, and it can serve as a foundation 
// for various graph-related tasks, such as finding connected components or shortest paths.
void create_AdjList(unordered_map<int, set<int>>& adjList, vector<pair<int, int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
//actual bfs function that uses q to find bfs and then store answer in ans vector
void bfs(unordered_map<int, set<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    //pushing the node in queue
    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for (auto i : adjList[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
//function to call actual bfs function for each node(vertex)
vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    create_AdjList(adjList, edges);

    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}
//creating class graph to use it again and again without writing big code
class Graph {
public:
    unordered_map<int, list<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;//visited array to mark 0 1

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (!direction) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    Graph g;
    for (int i = 0; i < m; i++) {
        cout<<"Enter Connecting Edges";
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false); // Assuming undirected edges
    }
    //note : the code is for undirected edges only
    g.printAdjList();
}
