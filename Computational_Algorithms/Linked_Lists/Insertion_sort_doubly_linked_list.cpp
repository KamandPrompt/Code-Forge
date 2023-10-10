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
    // cout<<(head==NULL)<<endl;
    if(head==NULL){
        head=n;
        // cout<<"bjh";
        return;
    }
    if(head->data>val){
        head->prev=n;
        n->next=head;
        head=n;
        return;
    }
    // cout<<"..";
    Node* temp=head;
    while(temp->next!=NULL){
        // cout<<"??";
        if(temp->data>val){
            n->next=temp;
            temp->prev->next=n;
            n->prev=temp->prev;
            temp->prev=n;
            // cout<<"...";
            return;
        }
        else{
            temp=temp->next;
        }
    }
    // cout<<temp->data<<endl<<val;
    if(temp->data>val){
        n->next=temp;
        if(temp->prev!=NULL){
            n->prev=temp->prev;
        temp->prev->next=n;
        }
        temp->prev=n;
        // cout<<"\\";
        return;
    }
    else{
        // cout<<"..";
        temp->next=n;
        n->prev=temp;
        // cout<<"<<";
    }
    // cout<<temp->data;
    return;
} 

//Defining function for display doubly linked list
void display(Node* head){
    Node* temp=head;
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
    Insert_sort(head,20);
    Insert_sort(head,10);
    Insert_sort(head,50);
    Insert_sort(head,5);
    display(head);
    return 0;  
}
