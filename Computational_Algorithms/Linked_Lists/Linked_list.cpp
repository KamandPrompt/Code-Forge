
/*
This is a cpp code for linked list.
Code includes following functions:
1.)We can insert front to a linked list.
    Time complexity:O(1)
2.)We can insert tail to a linked list.
    Time complexity:O(1)
3.)Print the linked list.We will start from head and traverse through the linked list.
    Time Complexity: O(n)
*/
#include<bits/stdc++.h>
using namespace std;

//Creating a node class with properties data and next address.
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

//Creating function to add tail
void insertTail(Node* &head,int val,Node* &tail){
    Node* n =new Node(val);
    //Checking for empty list.
    if(head==NULL){
        head=n;
        tail=n;
        //cout<<head<<endl;
        return;
    }
    //Add tail
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    tail=n;
}

//function to insert head
void Insert_Head(Node* &head,int val){
    Node* n= new Node(val);
    n->next=head;
    head=n;
}

//Code to print the linked list
void display(Node* head){
    //checking for empty list
    if(head==NULL){
        cout<<"List is empty!!"<<endl;
    }
    else{
        Node* temp=head;
        while(temp->next !=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data;
        cout<<endl;
    }
    
}

//Driver code
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