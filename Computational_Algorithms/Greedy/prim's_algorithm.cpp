/*PRIM'S ALGORITHM FOR MINIMUM SPANNING TREE*/

/*if we have a graph whose nodes are connected to each other acyclic or cyclic and the paths have some
  weight then we can find out the minimum weighted path which connects all node.
*/

/* OBSERVATIONS-
  1)if there are n nodes then there will be n-1 paths which connects all nodes.
  2)if we have 2 non connected graph then we can never find minimum spanning path using this algo.
*/

/*ALGORITHM
    1)create three arrays parent,weight,visited.
    2)initialise weight vector with max value and visited vector with false.
    3)we can start with any node(usually node 0) then select node whose path with this node is least
      and update the parent for this node.
    4)as we select paths we will also update weights in weight array with minimum of weights 
      and value stored in weights array.
    5)once we have visited the node we update value in visited array as true.
    6)we then select minimum value in array weights and repeat step 4-6 till we get parent of
      each node filled.
*/

#include<bits/stdc++.h>
using namespace std;

//finding node with minimum value of weight.
int node(vector<int>& weight,vector<bool>& visited,int V)
{
	int minimum = INT_MAX;
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(visited[i]==false && weight[i]<minimum)
		{
			vertex = i;
			minimum = weight[i];
		}
	}
	return vertex;
}

//creating a spanning tree.
void spanningTree(vector<vector<int>> graph,int V)
{
	int parent[V];// creating parent array.
	vector<int> weight(V,INT_MAX);// setting weight of each node initially maximum/infinity.
	vector<bool> visited(V,false);// setting initial visited array as false none visited.


	parent[0] = -1;	//as we are taking 0 is base node so it will have no parent
	weight[0] = 0;	//cost of going to node 0 from node 0 would be 0


	for(int i=0;i<V-1;i++)
	{	
		int U = node(weight,visited,V);
		visited[U] = true;	

		for(int j=0;j<V;j++)
		{
			if(graph[U][j]!=0 && visited[j]==false && graph[U][j]<weight[j])
			{
				weight[j] = graph[U][j];
				parent[j] = U;
			}
		}
	}

	int cost=0;

	for(int i=1;i<V;i++){
		cout<<"nodes connected: "<<parent[i]<<"->"<<i<<"  weight = "<<graph[parent[i]][i]<<endl;
		cost+=graph[parent[i]][i];
	}
	cout<<"cost of traversing spanning tree is "<<cost<<endl;
}

int main()
{
    int V;
    cout<<"enter number of vertices/nodes."<<endl;
    cin>>V;

    vector<vector<int>> graph(V,vector<int>(V));
    
    int n;
    cout<<"enter number of edges"<<endl;
    cin>>n;

    for (int i = 0; i <n ; i++)
    {
        int p,q;
        cout<<"enter the connecting nodes and weight of path in order node1,node2 and path weight"<<endl;
        cin>>p>>q;
        if(p<0||p>V-1||q<0||q>V-1){
			cout<<"please keep input in range."<<endl;
			return 0;
		}

		int val;
		cout<<"enter the weight of path"<<endl;
		cin>>val;
		graph[p][q]=val;
		graph[q][p]=val;
    }
    
	/* adjacency matrix for inputs-
		6 10
		0 1 4
		0 2 6
		1 2 6
		1 3 3 
		1 4 4
		2 4 8 
		4 5 7
		2 3 1
		3 4 2 
		3 5 3

		would look like this-

	   [[0, 4, 6, 0, 0, 0],
		[4, 0, 6, 3, 4, 0],
		[6, 6, 0, 1, 8, 0],
		[0, 3, 1, 0, 2, 3],
		[0, 4, 8, 2, 0, 7],
		[0, 0, 0, 3, 7, 0]]
    */

	spanningTree(graph,V);	
	return 0;
}

//TIME COMPLEXITY: O(V^2) but can be improved further like if we 
//				   would have used adjacency list instead of matrix.