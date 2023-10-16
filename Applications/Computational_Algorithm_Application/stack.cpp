//STACK APPLICATION IN REAL LIFE

/*in real world stack sata structure is used for
    1)backward and forward button in browsers
    2)memory management in computer programming
    3)delimiter checking
    4)undo and redo options 
    5)implementation recursion in programming
    etc.
*/

/*here we look at some of the real life implementation on small scale which can be enlarged for large data later
    1)undo and redo
    2)delimiter

    code is very simple and self explanatory so no comments are given.
*/

#include<bits/stdc++.h>
using namespace std;


void print(vector<int>arr){
    cout<<"operation performed in order: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void Undo(stack<int>&s,stack<int>&t,vector<int>arr){
    if(s.size()==0){
        cout<<"nothing to undo";
        return;
    }
    t.push(s.top());
    s.pop();
    cout<<"undo done:"<<endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return;
}

void Redo(stack<int>&s,stack<int>&t,vector<int>arr){
    if(t.size()==0){
        cout<<"nothing to redo"<<endl;
        return;
    }
    s.push(t.top());
    t.pop();
    cout<<"redo done:"<<endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return;
}
//delimiter is a way of checking if an sequence have an end for every start
// here look that application with use of brackets balancing.

void delimiterCheck(string l){
    stack<char>s;
    for (int i = 0; i < l.length(); i++)
    {
        if(l[i]=='('||l[i]=='{'||l[i]=='['){
            s.push(l[i]);
        }
        else if (l[i]==')'||l[i]=='}'||l[i]==']')
        {
            if(s.empty()==true){
                cout<<"brackets are not balanced"<<endl;
                return;
            }

            char top=s.top();
            if((top=='('&&l[i]==')')||(top=='{'&&l[i]=='}')||(top=='['&&l[i]==']')){
                s.pop();
            }
            else {
                cout<<"brackets are not balanced";
                return;
            }
        }
    }
    if(s.empty()==true){
        cout<<"brackets are balanced"<<endl;
        return;

    }
    else{
        cout<<"brackets are not balanced"<<endl;
        return;
    }
}

int main(){
    int n;
    cout<<"enter number of operation you want to perform: ";
    cin>>n;

    vector<int>arr;
    stack<int>s;
    stack<int>t;

    for(int i=0;i<n;i++)
    {
        int k;
        cout<<"enter operation number you want to perform(integer value): ";
        cin>>k;
        arr.push_back(k);
        s.push(k);    
        print(arr);
    }

    int chk=0;
    cout<<"perform undo/redo/none (type 0/1/else): ";
    cin>>chk;
    if(chk==1)Redo(s,t,arr);
    else if(chk==0)Undo(s,t,arr);

    cout<<"to check bracket balancing give any operation(eg- (1+2)*5 ): ";
    string l;
    cin>>l;
    delimiterCheck(l);
    return 0;
}