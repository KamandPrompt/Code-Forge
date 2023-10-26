#include<bits/stdc++.h>
using namespace std;
class Stack {
    public:
    int*array;
    int top;
    int size;

    Stack(int size){
        this ->size =size;
        array = new int[size];
        top = -1;
    }
    int peek(){
        if(top>=0 && top <size){
            return array[top];
        }
        else {
            cout<<"nothing left in stack";
            return 0;
        }
    }
    void push(int data){
        if(size - top> 1){
            top++;
            array[top]=data;
        }
        else {
            cout<<" stack is overflown " ; 
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<" no data element to remove " ;
        }
    }

    bool isEmpty(){
        if (top == -1){
            return 1;
        }
        else {
            return 0;
        }
    }
};
int main()
{
    Stack s(5);
    s.push(1);
    s.push(4);
    s.push(3);
    s.push(8);
    s.push(10);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty();
    return 0;
}