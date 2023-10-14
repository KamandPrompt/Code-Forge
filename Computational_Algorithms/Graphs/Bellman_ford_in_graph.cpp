/*
Bellman-ford algorithm is used to find shortest distance between source and vertices.

Stepwise algorithm:
1) Initialization: Assign an initial value of infinity to the distance between the source vertex and all other vertices, except 
for the source vertex itself, which is set to zero.
2) Relaxation: For each edge (u, v) with weight w in the set of edges E, if the sum of the distance to vertex u and the weight
of edge (u, v) is smaller than the current distance to vertex v, update the distance to v.
3) Negative Cycle Check: Repeat the relaxation step for every edge in the graph. If a shorter path is still found, it indicates
the presence of a negative cycle.

Time complexity: O(|V|*|E|)
|V| is the number of vertices and |E| is the number of edges in the graph. This is because each vertex is relaxed |V|-1 times 
and each relaxation operation takes O(|E|) time.
*/
#include <bits/stdc++.h>
using namespace std;

//defining class edge
class Edge {
public:
    int source;
    int destination;
    int weight;

    Edge(int src, int dest, int wt) : source(src), destination(dest), weight(wt) {}
};

class BellmanFord {
public:
    //defining function to find distance
    void bellmanFord(vector<Edge>& edges, int numVertices, int source) {
        //INITIALIZATION
        vector<int> distances(numVertices, INT_MAX);
        distances[source] = 0;

        //RELAXATION:traverse through edges to find shortest distance
        for (int i = 1; i <= numVertices - 1; ++i) {
            for (const auto& edge : edges) {
                int u = edge.source;
                int v = edge.destination;
                int w = edge.weight;
                //if new distance is less than current distance->change
                if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
                    distances[v] = distances[u] + w;
                }
            }
        }

        // Check for negative cycle
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
// Main code
int main() {
    // Defining edge vector
    vector<Edge> edges = {
        {0, 1, 6},
        {0, 2, 2},
        {1, 4, 1},
        {2, 1, 3},
        {2, 3, 5},
        {3, 4, -3},
        {4, 3, 3}
    };
    //Defining source node and number of vertices
    int numVertices = 5;
    int sourceNode = 0;

    BellmanFord bf;
    bf.bellmanFord(edges, numVertices, sourceNode);

    return 0;
}
/*
Code contibuted by:-
Abhijeet Kumar Jha
B22149
*/