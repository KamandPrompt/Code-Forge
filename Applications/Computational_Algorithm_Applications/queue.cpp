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
    Queue(int size)
    {
        front=-1,back=-1;
        size=size;
        arr=new int[size];//memory allocation of size*int to queue
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
    cout<<peek(q,k);//printing 3rd element of queue



    return 0;
}