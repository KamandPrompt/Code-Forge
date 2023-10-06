#include<iostream>
using namespace std;

// Singly Linked List
class singly_linked_node{
    public:
    int value;
    singly_linked_node* next;

    singly_linked_node(int value){
        this->value=value;
        next=NULL;
    }
    
};

void head_push_back(singly_linked_node* &head,int k){
    singly_linked_node* a=new singly_linked_node(k);
    a->next=head;
    head=a;
}

void tail_push_back(singly_linked_node* &head,int k){
    if(head==NULL){
        head_push_back(head,k);
        return;
    }
    singly_linked_node* a=new singly_linked_node(k);
    singly_linked_node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=a;
}

bool iscircular(singly_linked_node* head){
    // FLoyd Circle Detection Algorithm
    singly_linked_node* slow=head;
    singly_linked_node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast==NULL || fast->next==NULL){
            return 0;;
        }
        fast=fast->next;
        slow=slow->next;
        if(fast==slow){
            return 1;
        }
    }
    return 0;
}

void print(singly_linked_node* &head){
    singly_linked_node* temp=head;
    cout<<"Array"<<endl;
    while(temp!=NULL){
        cout<<temp->value<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

void createLoop(singly_linked_node* &head, int k){
    if(k==-1){
        return;
    }

    // temp will point to kth node
    singly_linked_node* temp=head;
    for(int i=1;i<=k-1;i++){
        temp=temp->next;
    }

    // temp2 points to last node
    singly_linked_node* temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }

    // Create Loop
    temp2->next=temp;
    return;
}

int main(){

    int n;
    cout<<"Enter the number of elements in the Linked List: ";
    cin>>n;
    singly_linked_node* list1=new singly_linked_node(1);
    
    for(int i=2;i<=n;i++){
        tail_push_back(list1, i);
    }

    cout<<"\nAdded numbers from 1 to "<<n<<" in the linked list.\n";

    print(list1);

    int nodeValue;
    cout<<"\nEnter node to loop back last node to(Input -1 for no loop): ";
    cin>>nodeValue;

    createLoop(list1, nodeValue);

    cout<<"\nCircular Check: "<<iscircular(list1);


    cout<<endl;
    delete list1;
    return 0;
}

