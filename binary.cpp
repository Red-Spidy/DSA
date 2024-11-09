#include <iostream>
#include <cstdlib>
using namespace std;

struct Stack {
    int data;
    struct Stack* next;
}*tos = NULL;

Stack* create_node(int data) {
    Stack* newnode = new Stack();
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
}

void insert_at_beg(Stack*& tos, Stack* node) {
    if (tos == NULL) {
        tos = node;
    } else {
        node->next = tos;
        tos = node;
    }
}

void pop(){
    if (tos == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    Stack* temp = tos;
    tos = tos->next;
    cout << temp->data;
    delete temp;
}
void fuc(int n){
    while (n != 0) {
        Stack* node = create_node(n % 2);
        n /= 2; 
        insert_at_beg(tos, node);
    }
    while (tos != NULL) {
        pop();
    }
}
int main() {
    int n;
    cin >> n;
    fuc(n);
    return 0;
}
