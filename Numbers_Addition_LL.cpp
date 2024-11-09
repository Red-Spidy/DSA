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
Node *reverse_using_Loop(Node* head){
    Node* prev =NULL;
    Node* curr = head;
    while(curr != NULL){
        Node *temp =curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;  
}
Node* solve(Node *head1, Node *head2){
    // Reverse Both the linked lists
    if(head1==NULL){
        return head2;

    }
    if(head2==NULL){
        return head1;
    }
    head1 = reverse_using_Loop(head1);
    head2 = reverse_using_Loop(head2);

    // Add Both the linked list 
   
    Node* anshead=NULL;
    Node* anstail = NULL;
    int carry =0;
    while(head1 != NULL && head2 != NULL){
        int sum = carry + head1->data + head2->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newnode = new Node(digit);
        // Attachong the node to answer waali linked list
        if(anshead == NULL){
            anshead = newnode;
            anstail = newnode;
        }
        else{
            anstail->next = newnode;
            anstail = newnode;
        }
        head1 = head1-> next;
        head2 = head2->next;
    }
    while(head1!=NULL){
        int sum = carry+ head1->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newnode = new Node(digit);
        anstail->next = newnode;
        anstail = newnode;
        head1 = head1->next;
    }
    while(head2!=NULL){
        int sum = carry+ head2->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newnode = new Node(digit);
        anstail->next = newnode;
        anstail = newnode;
        head2 = head2->next;
    }
    while(carry !=0){
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;
        Node* newnode = new Node(digit);
        anstail->next = newnode;
        anstail = newnode;
    }
    anshead = reverse_using_Loop(anshead);
    return anshead;
    // Reverse the answer linked list

}    
int main(){
    Node* head1 = new Node(2);
    Node* second1 = new Node(4);
    head1->next = second1;
    second1->next = NULL;
    Node* head2 = new Node(2);
    Node* second2 = new Node(3);
    Node* third2 = new Node(4);
    head2->next = second2;
    second2->next = third2;
    third2->next = NULL;
    // cout<<"Function NOt Running"<<endl;
    Node* ans =solve(head1,head2);
    // cout<<"Function Running"<<endl;
    print(ans);

    return 0;
}