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
Node *reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
bool checkPalindrome(Node *&head){
    if(head== NULL){
        cout<<"The Linked List is empty"<<endl;
        return true;
    }
    if(head->next ==NULL){
        return true;
    }
    //NOde greter than 1
    Node* mid = middle_Node(head);
    Node* reversell = reverse(mid->next);
    mid->next = reversell;
    // Start Comparision
    Node* temp1 =head;
    Node* temp2 =reversell;
    while(temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}
int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(30);
    // Node* fifth = new Node(20);
    // Node* sixth = new Node(10);
    head->next =second;
    second->next =NULL;
    // third->next= fourth;
    // fourth->next = fifth;
    // fifth->next =sixth;
    // sixth->next =NULL;

    bool isPalindrome = checkPalindrome(head);
    if(isPalindrome){
        cout<<"The List Is palidrome"<<endl;
    }
    else{
        cout<<"LInk lIs t is not palindrome"<<endl;
    }
    return 0;
}
// Sabse pehle Middle dhundo
// Middle ke aage waali linked list ko reverse krdo
// Join krwao linked list
// Comparision Start krdo