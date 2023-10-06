/*BINARY TREE ORDER TRAVERSAL(DFS Traversal)*/

/*Traversing tree in different orders-
    preorder is <root><left><right> traversal in order
    inorder is <left><root><right> traversal in order
    postorder is <left><right><node> traversal in order
*/

/*TREE 
                        0
                       / \
                      1   2
                     / \ / \
                     ....... so on
*/

//formation of tree
#include<bits/stdc++.h>
using namespace std;
struct binary_Tree
{
    int val;
    binary_Tree* left;
    binary_Tree* right;
};

/*PREORDER ALGORITHM IS
    1)if you point to a root.. print it
    2)move left if it exists 
    3)move right if it exists
    4)do this till you have traversed the complete tree
*/

/*FOR TREE-
                        A
                       / \
                      /   \
                     B     C
                    / \   / \
                   D   E  F  G
                   \     /   /
                    H   I   J
    
    PREORDER = A,B,D,H,E,C,F,I,G,J
*/
void preorder(binary_Tree* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<' ';//printing the value
    preorder(root->left);//moving left
    preorder(root->right);//moving right
}

/*FOR TREE-
                        A
                       / \
                      /   \
                     B     C
                    / \   / \
                   D   E  F  G
                   \     /   /
                    H   I   J
    
    inorder=D,H,B,E,A,I,F,C,J,G
    -if you know concept of binary tree you will see that this 
     arrangement is in ascending order.
*/
void inorder(binary_Tree* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);//moving left
    cout<<root->val<<' ';//printing the value
    inorder(root->right);//moving right
}

/*FOR TREE-
                        A
                       / \
                      /   \
                     B     C
                    / \   / \
                   D   E  F  G
                   \     /   /
                    H   I   J
    
    postorder= H,D,E,B,I,F,J,G,C,A
*/
void postorder(binary_Tree* root){
    // cout<<"postorder is: ";
    if(root==NULL){
        return;
    }
    postorder(root->left);//moving left
    postorder(root->right);//moving right
    cout<<root->val<<' ';//printing the value
}


//assuming you know insertion in binary tree
binary_Tree* insert(binary_Tree*root,int value){
    if(root==NULL){
       binary_Tree* newNode=new binary_Tree();
       root=newNode;
       newNode->val=value;
    }
    else if(value<=root->val){
        root->left=insert(root->left,value);
    }
    else if(value>root->val){
        root->right=insert(root->right,value);
    }
    return root;
}

int main(){
    binary_Tree* root=NULL;
    int n;
    cout<<"enter number of nodes to be added"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cout<<"enter element to be inserted"<<endl;
        cin>>a;
        root=insert(root,a);
    }
    cout<<"preorder is: ";
    preorder(root);
    cout<<endl;
    cout<<"inorder is: ";
    inorder(root);
    cout<<endl;
    cout<<"postorder is: ";
    postorder(root);

    return 0;
}