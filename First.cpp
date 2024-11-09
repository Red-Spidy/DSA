#include <iostream>
#include <cstdlib>
using namespace std;
struct LL{
    int data;
    struct LL *next;
} *head = NULL;
struct LL *create_node(){
    struct LL *new_node = (struct LL*) malloc(sizeof(struct LL));
    new_node -> next = NULL;
    cout<<"Enter Data"<<endl;
    cin>>new_node ->data;
    return new_node;
}
struct LL *insert_at_end(struct LL *&head,struct LL *new_node){
    struct LL *temp;
    temp = head;
    if(head == NULL){
        head = new_node;
    }
    else{
        while(temp->next != NULL){
            temp =temp ->next;}
        temp->next = new_node;
    }
    return head;
}
struct LL *insert_at_beg(struct LL *&head,struct LL *newnode){
    if(head == NULL){
        head = newnode;
    }
    else{
    newnode->next = head;
    head = newnode;
    }
    return head;
}
//Insert At MIddle after given data
struct LL *insert_at_middle(struct LL *newnode,int data,struct LL *&head){
    struct LL *temp;
    temp = head;
    if(head->data == data){
        newnode ->next = head ->next;
        head->next = newnode;
    }
    else{
        while(temp -> data != data){
            temp = temp ->next;
        }
        newnode -> next = temp->next;
        temp ->next = newnode;
    }
    return head;
}

void print_data(struct LL *head){
    struct LL *temp;
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->"<<endl;
        temp= temp->next;
    }
}
int main(){
    LL *a = create_node();
    insert_at_end(head,a);
    LL * b = create_node();
    insert_at_end(head,b);
    LL *c = create_node();
    insert_at_beg(head,c);
    LL *d = create_node();
    insert_at_middle(d,35,head);
    print_data(head);
    return 0;
}