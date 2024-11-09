//Checking a Pallaindrome using a DOuble LInked LIst

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
struct DL{
    struct DL* prev;
    char data;
    struct DL* next;
}*head = NULL , *tail=NULL;
DL *create_node(){
    DL* newnode = new DL;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
DL *insert_at_end(DL *&head,DL *&tail,DL *newnode){
    if(head==NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        }
}
void check_palindrome(DL* head, DL* tail){
    DL *temp1, *temp2;
    bool flag =true;
    temp1 =head;
    temp2 = tail;
    while(temp1 != temp2){
        if(temp1->data != temp2->data){
            flag =false;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }
    if(flag){
        cout<<"Pallindrome "<<endl;
    }
    else{
        cout<<"Not a Pallindrome"<<endl;
    }
    
}
int main(){
    string n;
    cout<<"Enter The String"<<endl;
    getline(cin,n);
    int len = n.length();
    for(int i=0;i<len;i++){
        DL* a = create_node();
        a->data = tolower(n[i]);
        insert_at_end(head,tail,a);
    }
    check_palindrome(head ,tail);
    return 0;
}