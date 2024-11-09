#include <iostream>
using namespace std;
int count(int arr[], int size, int n){
    int flag =0;
    for(int i =0; i<size;i++)
    {
        if(arr[i]==n){
            flag++;
        }
    }
    return flag;
}
int main()
{
    int n;
    cin>>n;
    int arr[5]= {1,1,1,7,0};
    cout<<count(arr,5,n);
    return 0;
}