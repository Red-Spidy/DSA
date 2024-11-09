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

void levelOrderTraversal(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
node *buildFromLevelOrderTraversal(node *root){
    queue <node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    q.push(root);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        cout<<"Enter Left Node for: "<< root->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter Right Node for: "<< root->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
int main(){

    node* root = NULL;

    // sample data 
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    root = buildTree(root);

    // Level Order Traversal
    levelOrderTraversal(root);
}