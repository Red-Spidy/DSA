#include <iostream>
using namespace std;
bool find(int a[],int size,int find){
    for(int i=0;i<size;i++){
        if(a[i]== find)
        return 1;
    }
}
int main()
{
    int n;
    cin>>n;
    bool flag=0;
    int arr[5]= {1,3,5,7,9};
    for(int i = 0;i <5;i++){
        if(arr[i]== n){
            flag =1;
        }
    }
    if(flag==1){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    if(find(arr,5,n)){
        cout<<"Mil gya bhai Mil gaya"<<endl;
    }
    return 0;
}