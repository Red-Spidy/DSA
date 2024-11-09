#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct node{
    string title;
    string author;
    float price;
    long ISBN;
    int Y_O_P; // Year of Publicatiuon
    int E_n; //Edition number
    string pub_name;
    struct node *next;
} *head1 = NULL;
struct node *create_node(){
    struct node* newnode = new node;
    newnode -> next  = NULL;
    cout << "Enter TITLE: " << endl;
    cin.ignore();
    getline(cin, newnode->title);

    cout << "\nEnter the AUTHOR: " << endl;
    //cin.ignore();
    getline(cin, newnode->author);

    cout << "\nEnter the PRICE: " << endl;
    //cin.ignore();
    cin >> newnode->price;

    cout << "\nEnter the ISBN Value: " << endl;
    cin >> newnode->ISBN;

    cout << "\nEnter the Year of Publication: " << endl;
    cin >> newnode->Y_O_P;

    cout << "\nEnter the EDITION: " << endl;
    cin >> newnode->E_n;
   
    cout << "\nEnter the PUBLISHER NAME: " << endl;
    cin.ignore();
    getline(cin, newnode->pub_name);

    return newnode;
}
struct node *insert_at_end(struct node *&head1, struct node *newnode){
    struct node *temp;
    temp =head1;
    if(head1==NULL){
        head1 =newnode;
    }
    else {
        while(temp->next!=NULL)
        {temp =temp -> next;}
        temp->next =newnode;
    }
    return head1;
}
struct node *delete_at_beg(struct node *head1){
    struct node *temp;
    temp =head1;
    head1 = temp->next;
    temp ->next = NULL;
    free(temp);
    return head1;
}
struct node *delete_at_middle(struct node *head1, string a){
    struct node *temp;
    temp =head1;
    if(head1->title == a){
        delete_at_beg(head1);
    }
    else{
    while(temp->next->title!=a){
        temp = temp ->next;
    }
    temp->next  = temp->next->next;
    }
    free(temp->next);
    return head1;
}
void search(struct node *head1,long a){
    struct node *temp;
    temp =head1;
    while(temp->ISBN != a){
        temp = temp->next;
    }
    cout<<"The Title of the Book "<<temp -> title<<endl;
    cout<<"The Author Of the book "<<temp -> author<<endl;
    cout<<"The Price OF the Book "<<temp->price<<endl;
    cout<<"The ISBN "<<temp -> ISBN<<endl;
    cout<<"The Book was published in "<<temp ->Y_O_P<<endl;
    cout<<"The edition of the book is "<<temp->E_n<<endl;
    cout<<"The publisher of the book id "<<temp ->pub_name<<endl;  
}
void print(struct node *head1){
    struct node *temp;
    temp = head1;
    while(temp!=NULL){
        cout<<"The Title of the Book "<<temp -> title<<endl;
        cout<<"The Author Of the book "<<temp -> author<<endl;
        cout<<"The Price OF the Book "<<temp->price<<endl;
        cout<<"The ISBN "<<temp -> ISBN<<endl;
        cout<<"The Book was published in "<<temp ->Y_O_P<<endl;
        cout<<"The edition of the book is "<<temp->E_n<<endl;
        cout<<"The publisher of the book id "<<temp ->pub_name<<endl; 
        temp = temp ->next;
    }
}
int main(){
    int n;
    cout<<"Enter no. of books you want to enter"<<endl;
    cin>>n;
    for(int i =0; i<n; i++){
        node *a = create_node();
        insert_at_end(head1,a);
    }
    print(head1);
    return 0;
}