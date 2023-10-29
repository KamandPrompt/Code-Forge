#include<bits/stdc++.h>
using namespace std;

// QUEUE IS BASED ON FIFO ->FIRST IN FIRST OUT
// 1:It is linear data-structure which primarily supports two types of operation enqueue and dequeue
// 2:It is used in many of the computational algorithms like Breadth First Search and queue helps in manage dataflow
// 3:Some of the application of queue are->
// Task Scheduling, Resource Allocation, Network Protocols, Operating Systems etc..

// One data structure which is modification of queue known as priority queue
// have many application in computational algorithms:
// like Dijkstra’s Shortest Path Algorithm, Prim’s algorithm, Heap Sort, etc..

// IMPLEMENTATION OF QUEUE as ABSTRACT DATA TYPE (queue adt)
struct Queue
{
    int size;
    int front;//should be initialise with value -1
    int back;//should be initialise with value -1
    int* arr;
    Queue(int sz)
    {
        front=-1,back=-1;
        size=sz;
        arr=new int[sz];//memory allocation of size*int to queue
    }
};

//function to chech whether queue is empty or not (queue underflow). TC=O(1)
int isEmpty(struct Queue* q)
{
    if(q->back==q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}   

//function to chech whether queue is full or not (queue overflow). TC=O(1)
int isFull(struct Queue* q)
{
    if(q->back==(q->size-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}   

// funtion to push element in queue TC->O(1)
void enqueue(struct Queue* q,int data)
{
    if(isFull(q))
    {
        cout<<"queue overflow"<<endl;
    }
    else
    {
        // back iterator will be incrementd and then element will be pushed at back of queue
        q->back++;
        q->arr[q->back]=data;
    }
}

// funtion to pop element from queue TC->O(1)
int dequeue(struct Queue* q)
{
    if(isEmpty(q))
    {
        cout<<"queue underflow"<<endl;
    }
    else
    {
        // front iterator will be incrementd and then element will be poped from front of queue
        q->front++;
        return q->arr[q->front];
    }
}

// funtion to return kth element from queue without removing it. TC->O(1)
int peek(struct Queue* q,int pos)//pos is not index
{
    if(isEmpty(q))
    {
        return -1;
    }
    else
    {return q->arr[q->front+pos];}

}

// funtion to print all element of queue TC->O(1)
void pr_q(struct Queue* q)
{
    int j=0;
    for (int i = q->front+1; i <=q->back; i++)
    {
        cout<<j+1<<"th element of queue :"<<q->arr[i]<<endl;
        j++;
    } 
}


//APPLICATION OF QUEUE --> Bredth First Search(BFS) using queue (adt) implemented above (not using inbuilt queue)

vector<int>v;//vector to store bfs of nodes of graph
vector<int> bfs_Of_Graph(int V, vector<vector<int>> adj)
{
    vector<int> v;
    int vis[V]={0};
    struct Queue* que=new struct Queue(V+1);//creating queue of size V+1
    enqueue(que,0);//first we will push 0 in queue considering the graph is connected at all and its node are numbered from 0 to V-1
    vis[0]=1;v.push_back(0);
    while(!isEmpty(que))
    {
        int t1=peek(que,1);//each time we store front element of queue
        dequeue(que);//and then pop it from queue
        for(auto i:adj[t1])//visit its all neighbour and push it in queue if it is not visited
        {
            if(!vis[i])
            {
                vis[i]=1;
                enqueue(que,i);
                v.push_back(i);
            }
        }
    }
    return v;    
}

int main()
{
    int q_size;
    cout<<"Enter size of queue"<<endl;
    cin>>q_size;
    struct Queue* q=new struct Queue(q_size);

    int noe;
    cout<<"Enter number of element you want to enqueue in queue"<<endl;
    cin>>noe;

    for (int i = 0; i < noe; i++)
    {
        int t;
        cout<<"Enter element you want to enqueue in queue"<<endl;
        cin>>t;
        enqueue(q,t);
    }
    
    cout<<"Printing queue after all enqueue operation"<<endl;
    pr_q(q);

    int nod;
    cout<<"Enter number of times you want to dequeue element from queue"<<endl;
    cin>>nod;//should be less than current size of queue

    for (int i = 0; i < nod; i++)
    {
        dequeue(q);
    }
    cout<<"Printing queue after all dequeue operation"<<endl;
    pr_q(q);


    int k;
    cout<<"Enter k where you want kth element of queue"<<endl;
    cin>>k;//should be less than current size of queue
    cout<<peek(q,k);//printing kth element of queue

    int nv,ne;
    cout<<"Enter number of nodes and edges in graph"<<endl;
    cin>>nv>>ne;
    vector<vector<int>> adj(nv+1);
    cout<<"Enter (u v) where there is an edge between u and v; enter total "<<ne<<" pairs"<<endl;
    // Creating adjacency list for graph
    for (int i = 0; i < ne; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>bfs=bfs_Of_Graph(nv,adj);//calling bfs function
    for (auto it:bfs)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    
    

    return 0;
}