//This code is of Bellman-ford algorithm for graphs which finds the shortest distance of vertices from the source provided.
//This code also detects negative cycle and prompts the user about the same.
#include <bits/stdc++.h>
using namespace std;

//Defining edge class with its three attributes
class Edge {
public:
    int source;
    int destination;
    int weight;
//definig initial parameter assignments
    Edge(int src, int dest, int wt) : source(src), destination(dest), weight(wt) {}
};

//Defining class for algorithm
class BellmanFord {
public:
    void bellmanFord(vector<Edge>& edges, int numVertices, int source) {
        //setting distance to maximum so that we can change later
        vector<int> distances(numVertices, INT_MAX);
        //distance of source =0
        distances[source] = 0;
        //checking for distance and assigning new distance if its less than current distance
        for (int i = 1; i <= numVertices - 1; ++i) {
            for (const auto& edge : edges) {
                int u = edge.source;
                int v = edge.destination;
                int w = edge.weight;
                if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
                    distances[v] = distances[u] + w;
                }
            }
        }

        // Check for negative cycles
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
                cout << "Graph contains negative cycle" << endl;
                return;
            }
        }

        // Print the shortest distances
        for (int i = 0; i < numVertices; ++i) {
            cout << "Distance from " << source << " to " << i << " is " << distances[i] << endl;
        }
    }
};

//Main code
int main() {
    //Defining edges of the graph
    vector<Edge> edges = {
        {0, 1, 6},
        {0, 2, 2},
        {1, 4, 1},
        {2, 1, 3},
        {2, 3, 5},
        {3, 4, -3},
        {4, 3, 3}
    };
    //defining source node
    int numVertices = 5;
    int sourceNode = 0;

    BellmanFord bf;
    bf.bellmanFord(edges, numVertices, sourceNode);

    return 0;
}
/*
Code conrivuted by:
Abhijeet Kumar Jha
B22149
*/