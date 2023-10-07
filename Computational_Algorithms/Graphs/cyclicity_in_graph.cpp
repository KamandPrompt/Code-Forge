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

/*LOGIC
    let us say that if two node are connected they will have same parent. i.e. if we consider an 
    example 1-2-3 we can say that 1 is parent of 2 and 2 is parent of 3 and since 1 is parent of 2 
    ultimately 1 becomes the parent of 3 and obviously 1 is parent of itself.
    therefore if we connect 1 and 3 directly we see geometrically that we will get a cycle.
    since both already had same parent we conclude that connecting 2 nodes with same parent leads to cyclicity.

    you can apply same logic while considering 2 to be the parent of 1 and 3 and then connecting 1 and 3 
    would give us same result.

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
        node=parent[node]; //here since we want to find ultimate parent of that node we iterate till we get it.
    }
    return node;// returning the ultimate parent of the node
}

void Union(int i,int j,vector<int>&parent){
    // union of node, i.e, setting parent as same.
    int iroot=find(i,parent);
    int jroot=find(j,parent);
    if(iroot!=jroot){
        parent[jroot]=iroot; //changing parent of current node from itself to its connecting node.
    }
}

bool dsu(vector<vector<int>>& edges) {
    //setting parent of each node to itself
    vector<int>parent(edges.size()+1);
    for(int i=0;i<edges.size()+1;i++)parent[i]=i;

    //appyling dsu
    for(auto edge:edges){
        if(find(edge[0],parent)==find(edge[1],parent))return true;//if parent of both node is same we have a cycle.
        Union(edge[0],edge[1],parent);//else we make one node parent of other.
    }
    return false;//if no nodes have same parent then we don't have a cycle
}

int main(){
    vector<vector<int>>graph;
    int n;
    cout<<"enter no. of nodes in your graph"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cout<<"enter the connected nodes i.e node1 and node2"<<endl;
        cin>>a>>b;//connected cities
        vector<int>v={a,b};
        graph.push_back(v);
    }
    
    /*
        graph is:
        2--1--5
        |  |
        3--4
    */
    
    bool ans= dsu(graph);//checking if graph is cyclic or not.
    if(ans)cout<<"graph is cyclic!"<<endl;
    else cout<<"graph is acyclic!"<<endl;
}
