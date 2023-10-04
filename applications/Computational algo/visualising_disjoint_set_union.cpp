/*DISJOINT SET UNION*/
/*Algorithm for finding if an undirected graph is cyclic or acyclic*/
/*prerequisites
    -basic knowledge about graphs
    -should know traversing in graph(BFS, DFS)
*/

/*SCENARIO
    There are n cities. They are connected by roads. If city 1 is connected directly with city 2,
    and city 2 is connected directly with city 3,...., city k is connected with city 1. then we say that 
    roads form a cycle. i.e.

    1---2---4                               1---2---4---5
    |  /\                                   |   |    \
    | /  \                                  |   |     \
    3     5---6                             6---3      7---8
    |
    |
    7

    in first case we see that roads connecting city 1,2,3 form a cycle.
    in second case we see that roads connecting ctiy 1,2,3,6 form a cycle.
*/

/*ALGORITHM
    1) first label each node as its parent node. i.e. each node is parent node of itself.
    2) then traverse across the graph and find parent of each node.
    3) if they have different parent do union of those 2, i.e. make thier parents same.
    4) if two node have same parent then it must be a cycle.
*/

#include <bits/stdc++.h>
using namespace std;

int find(int node,vector<int>&parent){
    //finding the parent node
    while(parent[node]!=node){
        node=parent[node];
    }
    return node;
}

void Union(int i,int j,vector<int>&parent){
    // union of node, i.e, setting parent as same.
    int iroot=find(i,parent);
    int jroot=find(j,parent);
    if(iroot!=jroot){
        parent[jroot]=iroot;
    }
}

bool dsu(vector<vector<int>>& edges) {
    //setting parent of each node
    vector<int>parent(edges.size()+1);
    for(int i=0;i<edges.size()+1;i++)parent[i]=i;

    //appyling dsu
    for(auto edge:edges){
        if(find(edge[0],parent)==find(edge[1],parent))return true;
        Union(edge[0],edge[1],parent);
    }
    return false;
}

int main(){
    vector<vector<int>>graph={{1,2},{2,3},{3,4},{1,5},{1,4}};
    /*
        graph is:
        2--1--5
        |  |
        3--4
    */
    bool ans= dsu(graph);

    if(ans)cout<<"graph is cyclic!"<<endl;
    else cout<<"graph is acyclic!"<<endl;
}