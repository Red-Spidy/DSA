#include <iostream>
#include<cstring>
using namespace std;
int main() {
    int arr[5] = {1,3,5,7,9};
    memset(arr,1,sizeof(arr));
    for(int i =0; i<5;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}