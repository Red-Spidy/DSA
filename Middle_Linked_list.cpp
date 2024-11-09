#include <iostream>
using namespace std;
class NOde{
    public:
    int data; 
    NOde* next;
    NOde(int data){
        this->data = data;
        this->next = NULL;
    }
};
void print(NOde* head){
    NOde* temp =head;
    while(temp!=NULL){
        cout<<temp -> data<<" ";
        temp = temp->next;
    }
}
NOde* middle_node(NOde *head){
    if(head==NULL){
        cout<<"Empty LL";
        return head;
    }
    if(head->next == NULL){
        return head;
    }
    NOde* slow =head;
    NOde* fast = head;
    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
    }
    return slow;
}
int main(){
    NOde* head = new NOde(10);
    NOde* second  = new NOde(20);
    NOde* third  = new NOde(30);
    NOde* fourth  = new NOde(40);
    NOde* fifth  = new NOde(50);
    head->next =second;
    second->next =third;
    third->next= fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    print(head);
    cout<<"Middle Node of the Functionm is "<<middle_node(head)->data<<endl;
    return 0;
}