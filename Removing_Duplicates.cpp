// Removing dupkicates from sorted linked list
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
Node* RemoveDuplicates(Node* head){
    if(head == NULL){
        return NULL;
    }
    if (head->next == NULL){
        cout<<"Singler node"<<endl;
        return head;
    }
    Node* curr = head;
    while(curr!=NULL){
        if(curr->next !=NULL && curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = temp->next;
            temp->next = NULL;
            delete(temp);
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}
void print(Node* head){
    Node* temp =head;
    while(temp!=NULL){
        cout<<temp -> data<<" ";
        temp = temp->next;
    }
}
int main(){
    Node* head = new Node(30);
    Node* second = new Node(30);
    Node* third = new Node(30);
    Node* fourth = new Node(30);
    Node* fifth = new Node(30);
    Node* sixth = new Node(30);
    head->next =second;
    second->next =third;
    third->next= fourth;
    fourth->next = fifth;
    fifth->next =sixth;
    sixth->next =NULL;
    print(head);
    cout<<"\n New LIst"<<endl;
    Node* newll = RemoveDuplicates(head);
    print(newll);
    return 0;
}
