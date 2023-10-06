#include<iostream>
using namespace std;

class Node{
    public:
    int level;
    int data;
    Node** forward;

    Node(int data,int level){
        this->data=data;
        forward=new Node*[level+1];
        for(int i=0;i<level+1;i++){
            forward[i]=NULL;
        }
    }
};
class Skiplist{
    int maxlvl;
    int clvl;
    Node* header;

    public:
    Skiplist(int m){
        maxlvl=m;
        header= new Node(-1,m+1);
        clvl=0;
    }
    
    int randomlvl(){
        int val=rand()%10;
        int val1=rand()%10;
        if ((val1-val>maxlvl)){
            return maxlvl;
        }
        else if(val1-val<=0){
            return 1;
        }    
        return val;
    }
    void insert(int x){
        Node* curr = header;
        Node* update[maxlvl+1];

        int lvl=randomlvl();
        clvl=lvl;
        for (int i=clvl;i>=0;i--){
            while(curr->forward[i]!=NULL && curr->forward[i]->data<x){
                curr=curr->forward[i];
            }
            update[i]=curr;
        }
        Node* toinsert = new Node(x,lvl);
        for(int i=lvl;i>=0;i--){
            toinsert->forward[i]=update[lvl-i]->forward[i];
            update[lvl-i]->forward[i]=toinsert;
        }
        cout<<x<<" has been inserted"<<endl;
    }

    void display(){
        Node*curr=header;
        for (int i=maxlvl;i>=0;i--){
            cout<<"At level "<<i<<" : ";
            while(curr!=NULL &&curr->forward[i]!=NULL){
                cout<<curr->forward[i]->data<<" ";
                curr=curr->forward[i];
            }
            cout<<endl;
            curr=header;
        }
    }
    bool search(int x){
        Node*curr=header;
        int count =0;
        for (int i=maxlvl;i>=0;i--){

            while(curr->forward[i]!=NULL && curr->forward[i]->data<x ){
                curr=curr->forward[i];
                count++;
            }
            if(curr->forward[i]!=NULL&&curr->forward[i]->data==x){
                cout<<count<<" no. of comparisons"<<endl;
                return true;
            }
        }
        return false;
    }
    
};

int main(){
    Skiplist l(3);
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(6);

    l.display();
    cout<<l.search(20);
}