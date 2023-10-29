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


// Level Order Traversal of Binary Tree
//  --> in this type of traversal , we print node of binary tree in increasing height order

// => algorithm :
//  1 : create a queue and push root in it
//  2 : run a loop until queue is not empty
//  3 : each time pop front element from queue and then print its value 
// and push its left and right child if exists

/*FOR TREE-
                        A
                       / \
                      /   \
                     B     C
                    / \   /  \
                   D   E  F   G
                  / \    / \  / \
                 H   I  J   K L  M
    
    level_order_traversal="ABCDEFGHIJKLM"
*/

void level_order_traversal(binary_Tree*root)
{
    queue<binary_Tree*>q;//creating a queue
    q.push(root);//pushing  root element first
    while(!q.empty())// running a loop until queue is not empty
    {
        auto node=q.front();q.pop();//each time we pop front element from queue 
        cout<<node->val<<" ";//, print its value 
        if(node->left){q.push(node->left);}//and then push its left 
        if(node->right){q.push(node->right);}//and right child if exist
    }
    cout<<endl;
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
    cout<<endl;
    cout<<"levelOrderTraversal is: ";
    level_order_traversal(root);
    return 0;
}