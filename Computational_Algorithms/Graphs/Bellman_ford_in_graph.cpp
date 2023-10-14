#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int source;
    int destination;
    int weight;

    Edge(int src, int dest, int wt) : source(src), destination(dest), weight(wt) {}
};

class BellmanFord {
public:
    void bellmanFord(vector<Edge>& edges, int numVertices, int source) {
        vector<int> distances(numVertices, INT_MAX);
        distances[source] = 0;

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

int main() {
    vector<Edge> edges = {
        {0, 1, 6},
        {0, 2, 2},
        {1, 4, 1},
        {2, 1, 3},
        {2, 3, 5},
        {3, 4, -3},
        {4, 3, 3}
    };
    int numVertices = 5;
    int sourceNode = 0;

    BellmanFord bf;
    bf.bellmanFord(edges, numVertices, sourceNode);

    return 0;
}