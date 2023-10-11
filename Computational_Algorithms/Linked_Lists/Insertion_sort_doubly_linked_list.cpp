/*This code is of insertion sort using doubly linked list which stores address of both 
next and previous node which helps in forward and reeverse traversa. This includes defining class Node and function for 
insert operation and printing the doubly linked list*/ 

#include<bits/stdc++.h>
using namespace std;

//Defining node for the program
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};
//Defining function for inserting a node
void Insert_sort(Node* &head,int val){
    Node* n=new Node(val);
    //checking for empty list
    if(head==NULL){
        head=n;
        return;
    }
    //if input is larger than current largest
    if(head->data>val){
        head->prev=n;
        n->next=head;
        head=n;
        return;
    }
    //Traverse till you find correct position
    Node* temp=head;
    while(temp->next!=NULL){
        //if found correct position: insert and return
        if(temp->data>val){
            n->next=temp;
            temp->prev->next=n;
            n->prev=temp->prev;
            temp->prev=n;
            return;
        }
        else{
            temp=temp->next;
        }
    }
    //checking for last element
    if(temp->data>val){
        n->next=temp;
        if(temp->prev!=NULL){
            n->prev=temp->prev;
        temp->prev->next=n;
        }
        temp->prev=n;
        return;
    }
    else{
        temp->next=n;
        n->prev=temp;
    }
    return;
} 

//Defining function for display doubly linked list
void display(Node* head){
    Node* temp=head;
    //Traversing through nodes
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<(temp->data)<<endl;
    return;
}

//Main driver code
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    //Code for taking input from user
    cout<<"Enter number of inputs:";
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        int x;cin>>x;
        Insert_sort(head,x);
    }
    cout<<"Sorted list: ";
    display(head);
    return 0;  
}

/*
Code contributed by-Abhijeet Jha
B22149
*/