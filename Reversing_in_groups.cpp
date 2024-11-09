#include <iostream>
using namespace std;
class Node{
    public:
    int data; 
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void print(Node* head){
    Node* temp =head;
    while(temp!=NULL){
        cout<<temp -> data<<" ";
        temp = temp->next;
    }
}
Node* middle_Node(Node *head){
    if(head==NULL){
        cout<<"Empty LL";
        return head;
    }
    if(head->next == NULL){
        return head;
    }
    Node* slow =head;
    Node* fast = head;
    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
    }
    return slow;
}
int getLength(Node *head){
    int len =0;
    Node* temp =head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
Node* reverseNodes(Node *&head,int k){
    if(head== NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
    }
    int len = getLength(head);
    if(k>len){
        //cout<<"Enter Valid value for K"<<endl;
        return head;
    }
    // Stepp 1
    // Reverse first K node of lInked List
    Node* prev = NULL;
    Node* curr =head;
    Node* forward = curr->next;
    int count  =0;
    while(count<k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if(forward!= NULL){
        // Wee Will have further notes to reversse 
        // Step 3   
        head->next =reverseNodes(forward,k);
    }
    //  Return ther prev
    return prev;
}
int main(){
    Node* head = new Node(10);
    Node* second  = new Node(20);
    Node* third  = new Node(30);
    Node* fourth  = new Node(40);
    Node* fifth  = new Node(50);
    Node* sixth = new Node(60);
    head->next =second;
    second->next =third;
    third->next= fourth;
    fourth->next = fifth;
    fifth->next =sixth;
    sixth->next = NULL;
    print(head);
    cout<<"Middle Node of the Functionm is "<<middle_Node(head)->data<<endl;
    head= reverseNodes(head,5);
    print(head);
    return 0;  
}