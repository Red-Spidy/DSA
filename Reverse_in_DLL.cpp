#include <iostream>
#include <cstdlib>
using namespace std;
struct LL
{
    int data;
    struct LL *next;
    struct LL *prev;
};
struct LL *head=NULL;
struct LL *tail =NULL;
LL *create_node(struct LL *&head){
    LL *a = (struct LL*) malloc(sizeof(struct LL));
    cout<<"Enter The data"<<endl;
    cin>>a->data;
    a->next =NULL;
    a->prev = NULL;
    return a;
}
LL *insert_at_end(struct LL *&head, struct LL *a){
    LL *temp;
    temp =head;
    if(head == NULL){
        head =a;
    }
    else{
        while(temp -> next !=NULL){
            temp = temp ->next;
        }
        temp -> next =a;
        a->prev = temp;
        tail =a;
    }
    return head;
}
LL *insert_at_beg(struct LL *&head,struct LL *node){
    LL *temp;
    temp =head;
    node ->next = head;
    head->prev = node;
    head = node;
    return head;
}
LL *search_and_return_prev(struct LL *head,int target){
    LL *temp,*temp1;
    temp =head;
    while(temp->data!= target || temp->next!=NULL){
        temp = temp->next;
    }
    temp1 = temp->prev;
    return temp1;
}
LL *Insert_at_middle(struct LL*&head, struct LL *a,int target){
    LL *temp,*temp1;
    temp = search_and_return_prev(head,target);
    temp1 = temp->next;
    a->next = temp1;
    a->prev = temp;
    temp->next = a;
    temp1->prev = a;
    return head;

}
LL *Insert_at_given_position(struct LL*&head, struct LL *a,int pos){
    LL *temp,*temp1;
    if(pos==1){
        insert_at_beg(head,a);
    }
    else{
        for(int i =1 ; i<pos; i++){
            temp1 = temp;
            temp = temp ->next; 
    }
    if(temp ==NULL){
        insert_at_end(head,a);
    }
    a->next = temp;
    a->prev  = temp1;
    temp1->next =a;
    temp->prev = a;
    }
    return head;

}
LL *delete_at_beg(struct LL *&head){
    LL *temp;
    temp =head;
    head = head->next;
    head->prev = NULL;
    temp->next=NULL;
    free(temp);
    return head;
}
LL *delete_At_end(struct LL *&head){
    LL *temp1;
    temp1 =head;
    while(temp1->next!=NULL){
        temp1= temp1 ->next;
    }
    temp1->prev->next = NULL;
    free(temp1);
}
LL *search(struct LL *head, int target){
    LL *temp;
    temp = head;
    while(temp->data != target || temp!=NULL){
        temp = temp-> next;
    }
    return temp;
}
void delete_at_mid(struct LL *&head,int target){
    LL *temp;
    temp = search(head,target);
    temp->prev->next = temp->next;
    temp->next-> prev = temp->prev;
    free(temp);
}
LL *find_target(struct LL *&head,int target){
    LL *temp;
    temp =head;
    while(temp->next !=NULL){
        if(temp ->data == target){
            cout<<"Found";
            break;
        }
        else{
            cout<<"NOt Found";
        }
    }
    return temp;
}
void print_LL(struct LL *head){
    LL *temp;
    temp = head;
    while(temp->next !=NULL){
        cout<<temp ->data<<" -> ";
    }
}
void delete_at_pos(struct LL *head, int pos){
    LL *temp, *temp1;
    temp =head;
    if(pos==1){
        delete_at_beg(head);
    }
    else{
        for(int i =1; i<pos;i++){
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"Out OF Index";
        }
        else{
            temp->prev->next = temp->next;
            temp->next-> prev = temp->prev;
            
        }
        free(temp);
    }
}
LL *update_value(struct LL *head,int original,int updated){
    LL *original_node = find_target(head,original);
    original_node->data = updated;
    return head;
}
void delete_linked_list(struct LL *&head){
    LL *temp;
    temp =head;
    while(head->next!=NULL){
        temp =head;
        free(temp);
        head = head->next;
    }
    free(head);
}
LL *reverse(LL *head){
    LL *right;
    
}

int main(){
    return 0;
}