#include <iostream>
#include<queue>
// Node - Ek element of tree
// Root - Starting point pf tree
//  Children node 
// Sibling jiske parents same ho
// Ancestor ek side pakdo or upar jaate jaao

using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        this->data =d;
        this->right = NULL;
        this->left = NULL;

    }
};
// nON LINEAR  data structure
// Creation of binary tree

node *buildTree(node *root){
    cout<<"Enter the data: "<<endl; 
    int data;
    cin>>data;
    // Creation of Root Node
    root = new node(data); 
    if(data ==-1){
        return NULL;
        // Waise hi ek reference lia hai
    }
    cout<<"enter Data for left for "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter Data for right for "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

// In case of Inorder Traversal first we print left niode4 then middle then right node
// Left Root Right

// In case of Pre order ewe go with Root Left Right


// In case of Postr order ewe go with Left Right Root 

void Inorder(node *root){
    queue<node*> q;
    // Base Case
    if(root == NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";

    Inorder(root->right);
   
}

void Preorder(node *root){
    queue<node*> q;
    // Base Case
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    

    Preorder(root->right);
   
}

void Postorder(node *root){
    queue<node*> q;
    // Base Case
    if(root == NULL){
        return;
    }
   
    Postorder(root->left);

    Postorder(root->right);
    cout<<root->data<<" ";
}
int main(){

    node* root = NULL;

    // sample data 
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    root = buildTree(root);

    // Level Order Traversal
    Inorder(root);

    cout<<"Pre Order Traversal"<<endl;
    Preorder(root);

    cout<<"Post Order Traversal"<<endl;
    Postorder(root);

}