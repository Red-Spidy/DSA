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
node *insertIntoBST(node *root,int data){
    if(root == NULL){
        // This is the first node
        root = new node(data);
        return root;
    }
    if(root->data >data){
        root->left = insertIntoBST(root->left,data);

    }

    else{
        root->right = insertIntoBST(root->right,data);

    }

    return root;
}

void takeInput(node *&root){
    int data;
    cin>>data;
    while(data !=-1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
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
// Assuming there are only unique elements

node* FindNodeinBST(node *root,int target){
    if(root==NULL){
        return NULL;
    }

    if(root->data == target){
        return root;
    }

    if(target>root->data){
        return FindNodeinBST(root->right, target);
    }else{
        return FindNodeinBST(root->left, target);
    }
}

int minimum(node *root){
    // BST mai left left jaate rho hume min value mil jayegi
    node *temp = root;
    if(temp== NULL){
        return -1;
    }
    while(temp->left!=NULL){
        temp = temp->left;
    }

    return temp->data;
}

int maximum(node *root){
    // BST mai right right jaate rho hume max value mil jayegi

    node *temp = root;
    if(temp== NULL){
        return -1;
    }
    while(temp->right!=NULL){
        temp = temp->right;
    }

    return temp->data;
}

// Inorder Predecessor ka mtlb uske left subtree ka sabse max value
// Inorder Successor ka mtlb uske right subtree ka sabse chhoti value
node *deletenodeBST(node *root, int target){
    
    if(root == NULL){
        return NULL;
    }
    if(root->data == target){

        if(root->left == NULL && root->right ==NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right !=NULL){
            node * child  = root->right;
            delete root;
            return child;
        }
        else if(root->left != NULL && root->right ==NULL){
            node *child = root->left;
            delete root;
            return child;
        }
        else{
            // both child
            // Find inorder predecessor in lst
            int inorderpre = maximum(root->left);
            // replace root->data value with inorder predecessor
            root->data = inorderpre;
            root->left = deletenodeBST(root->left, inorderpre);
            return root;
        }

    }
    else if(target>root->data){
        root->right = deletenodeBST(root->right, target);

    }
    else if(target<root->data){

        root->left = deletenodeBST(root->left, target);
    }

    return root;

}
int main(){
    node *root = NULL;
    cout<<"Enter The data For root node"<<endl;
    takeInput(root);
    cout<<"Printing the data"<<endl;
    levelOrderTraversal(root);

    // bool ans  = FindNodeinBST(root,15);
    // cout<<"Present "<<ans<<endl;
    // cout<<minimum(root);
    // cout<<maximum(root);
    deletenodeBST(root, 100);
    levelOrderTraversal(root);
    return 0;
} 

// Average case mai time complexity O(Height) i.e O(log n)