
/*
This is a cpp code for linked list.
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

void insertTail(Node* &head,int val,Node* &tail){
    Node* n =new Node(val);
    if(head==NULL){
        head=n;
        tail=n;
        //cout<<head<<endl;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    tail=n;
}

void Insert_Head(Node* &head,int val){
    Node* n= new Node(val);
    n->next=head;
    head=n;
}
void display(Node* head){
    Node* temp=head;
    while(temp->next !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertTail(head, 60,tail);
    display(head);
    insertTail(head, 40,tail);
    insertTail(head, 30,tail);
    Insert_Head(head, 10);
    Insert_Head(head, 20);
    display(head);
    cout<<tail->data;
    return 0;  
}
/*
Code contributed by-
Abhijeet Kumar Jha
B22149
*/