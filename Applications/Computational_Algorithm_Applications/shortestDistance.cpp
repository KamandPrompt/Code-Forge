#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Define a structure to represent an edge and its weight
struct Edge {
    int to;
    int weight;
};

// Define a structure to represent a node with its distance from the source node
struct Node {
    int index;
    int distance;

    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

// Dijkstra's algorithm function
vector<int> dijkstra(const vector<vector<Edge>>& graph, int source) {
    int n = graph.size();
    vector<int> distance(n, INF);
    distance[source] = 0;
    
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({source, 0});
    
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        
        int u = current.index;
        int dist = current.distance;
        
        if (dist > distance[u]) {
            continue; // Skip outdated distances
        }
        
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;
            
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({v, distance[v]});
            }
        }
    }
    
    return distance;
}

int main() {
    int n, m; // Number of nodes and edges
    cin >> n >> m;
    
    vector<vector<Edge>> graph(n);
    
    // Read the edges and their weights
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    int source, destination;
    cin >> source >> destination;
    
    vector<int> shortestDistances = dijkstra(graph, source);
    
    if (shortestDistances[destination] == INF) {
        cout << "No path found between " << source << " and " << destination << endl;
    } else {
        cout << "Shortest distance from " << source << " to " << destination << ": " << shortestDistances[destination] << endl;
    }
    
    return 0;
}