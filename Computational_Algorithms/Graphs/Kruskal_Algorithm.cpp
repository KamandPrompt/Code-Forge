/*  Kruskal Algorithm is used for finding the minimum spanning tree of a Given graph.
    It works faster compared to Prims's Algorithm for spare graph.
    It can generate forest at any instant.
    It works on disconnected components as well
    This algorithm uses disjoint Set Datastructure additionally.
    Time Complexity : O(ElogV) 
*/

#include<bits/stdc++.h>
using namespace std;

// Disjoint set Datastructure implementation
const int N = 1e5 + 10;
int parent[N],size[N];

void make_set(int v){
    parent[v]=v;
    size[v]=1;
}

int find(int v){
    if(parent[v]==v){
        return v;
    }
    return parent[v] = find(parent[v]);
}
//Union by size operation using path compression

void Union(int a,int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}

int kruskal(vector<pair<int,pair<int,int>>> graph,int v,int start){
    //sort edges according to their weights
    sort(graph.begin(),graph.end());

    // make each vertex an individual set
    for(int i=start;i<=v;i++){
        make_set(i);
    }

    int total_cost=0;

    // iterate through the sorted edges by weight
    for(auto &i: graph){
        int wt = i.first;
        int u = i.second.first;
        int v = i.second.second;
        if(find(u)==find(v)) continue;// if including this edge in our tree forms a cycle move to the next step

        total_cost+=wt;
        Union(u,v);// if adding this edge is valid create Union of edges u and v
    }

    return total_cost;// return the total cost of spanning tree
}

int main(){
    int v,e;
    cin>>v>>e;// Enter number of vertices, edges 

    vector<pair<int,pair<int,int>>> graph;

    for(int i=0;i<e;i++){
        int x,y,wt; //(Enter vertices from 0 to v-1)
        cin>>x>>y>>wt;
        graph.push_back({wt,{x,y}});
        graph.push_back({wt,{y,x}});
    }

    cout<<kruskal(graph,v,0);// returns the total_cost of spanning tree
}