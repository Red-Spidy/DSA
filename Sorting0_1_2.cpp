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
    Node(){
        this->data=0;
        this->next =NULL;
    }
};
void print(Node* head){
    Node* temp =head;
    while(temp!=NULL){
        cout<<temp -> data<<" ";
        temp = temp->next;
    }
}
// Approach1
void sorting1(Node *head){
    Node* temp =head;
    int c1=0;
    int c0=0;
    int c2 =0;
    while(temp!=NULL){
        if(temp->data==1){
            c1++;
        }
        else if(temp->data == 0){
            c0++;
        }
        else if(temp->data==2){
            c2++;
        }
        temp = temp->next;
    }
    temp= head;
    while(c0--){
        temp ->data =0;
        temp = temp->next;
    }
    while(c1--){
        temp ->data =1;
        temp = temp->next;
    }
    while(c2--){
        temp ->data =2;
        temp = temp->next;
    }
}
Node* sorting2(Node *head){
    if(head==NULL){
        cout<<"Empty linked list"<<endl;
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    // Traverse the original Linked List
    Node* curr =head;
    while(curr!=NULL){
        if(curr->data == 0){
            Node* temp =curr;
            curr = curr->next;
            temp->next = NULL;
            // Maine ab node separater krdi
            // Appending it to head waali linked list
            zerotail->next = temp;
            zerotail =temp;
        }
        else if(curr->data==1){
            Node* temp =curr;
            curr = curr->next;
            temp->next = NULL;
            // Maine ab node separater krdi
            // Appending it to head waali linked list
            onetail->next = temp;
            onetail =temp;
        }
        else if(curr->data == 2){
            Node* temp =curr;
            curr = curr->next;
            temp->next = NULL;
            // Maine ab node separater krdi
            // Appending it to head waali linked list
            twotail->next = temp;
            twotail =temp;
        }
    }
    // Ab yuaha -pe teeno linked list ready hain

    // Remove NOdes
    // Modify One waali liked list
    Node* temp =onehead;
    onehead = onehead->next;
    temp->next = NULL;
    delete temp;

    // MOdify Two waali LIst
    temp = twohead;
    twohead = twohead->next;
    temp->next = NULL;
    delete temp;
    // Join them
    if(onehead != NULL){
        zerotail->next = onehead;
        if(twohead!= NULL)
            onetail->next = twohead;
        

    }
    else{
        // Onne waalim list empty hai
        if(twohead!= NULL){
            zerotail->next = twohead;
        }
    }
    temp =zerohead;
    zerohead = zerohead->next;
    temp->next =NULL;
    delete temp;

    // Return head of the mopdified linked lisyt
    return zerohead;
}
// Using count approach
int main(){
    Node* head = new Node(0);
    Node* second  = new Node(1);
    Node* third  = new Node(2);
    Node* fourth  = new Node(2);
    Node* fifth  = new Node(0);
    Node* sixth = new Node(1);
    head->next =second;
    second->next =third;
    third->next= fourth;
    fourth->next = fifth;
    fifth->next =sixth;
    sixth->next = NULL;
    print(head);
    //sorting1(head);
    cout<<"New List "<< endl;
    head =sorting2(head);
    print(head);
    return 0;
}
// Not a good approach kyukinisme elements ko humareplace kr rhe hain
// Interviewer hku,mein nbolega tune replace ni krnq hai
