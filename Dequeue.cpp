// Doubly ended queue
// push will be done from both sides
// pop will be done form bith sides
#include <iostream>

#include<deque>

using namespace std;

// Circular doubly emnded queue isme dekh lete hain

class Deque{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size){
        this->size = size;
        arr = new int[size];
        front =-1;
        rear =-1;

    }

    void pushrear(int data){
        // Queue Full
        // Single Elemet Case
        // Circluar Nature 
        // Normal Flow

        if(front ==0 && rear == size-1){
            cout<<"Q is full"<<endl;
            return;
        }
        else if(front-rear==1){
            cout<<"Q is full"<<endl;
            return;
        }
        else if(front==-1){
            front=rear=0;
            arr[rear] =data;
        }
        else if(rear == size-1 && front!=0){
            rear =0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pushfront(int data){
        if(front ==0 && rear == size-1){
            cout<<"Q is full"<<endl;
            return;
        }
        else if(front-rear==1){
            cout<<"Q is full"<<endl;
            return;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(front==0 && rear !=size-1){
            // Front mera empty ni hai but meri size -1 waali posiyon empty hai to mi fir waha jaaunga

            front =size-1;
        }
        else{
            front--;
        } 
        arr[front] = data;
    }

    void popFront(){
        // Empty check]

        // ?Single element 

        // circular nature

        // general flow
        if(front ==-1){
            cout<<"Queu is empty"<<endl;
            return;
        }
        else if(front==rear){
            arr[front] =1;
            front = -1;
            rear =-1;

        }
        else if(front == size-1){
            arr[front] = -1;

            front =0;
        }
        else{
            arr[front] = -1;
            front++;
        }
        
    }

    void popRear(){
        // EWmpty Checking
        // Single element;
        // Rear ==0 then rear jaayega size-1 pe

        // Normal case rear--
        if(front ==-1){
            cout<<"Queu is empty"<<endl;
            return;
        }
        else if(front==rear){
            arr[front] =1;
            front = -1;
            rear =-1;

        }
        else if(rear==0){
            arr[rear] =-1;
            rear = size-1;
        }
        else{
            arr[rear] =-1;
            rear--;
        }
        
    }
};

int main(){
    // Now using The STL
    deque<int> dq;
    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);
    cout<<"Size "<<dq.size()<<endl;
    dq.pop_front();
    cout<<"Size "<<dq.size()<<endl;
    dq.pop_back();
    cout<<"Size "<<dq.size()<<endl;
    
    cout<<"Front "<<dq.front()<<endl;

    cout<<"Rear "<<dq.back()<<endl;

    if(dq.empty()){
        cout<<"It is empty";
    }
    else{
        cout<<"It si not empty";
    }

    return 0;

}
