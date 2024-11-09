#include <iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> Res;
    int arr[]={1,2,3,4,5};
    int brr[]= {6,7,8,9};
    for(int i = 0 ; i<5;i++){
        Res.push_back(arr[i]);
    }
    for(int i =0; i<4;i++){
        Res.push_back(brr[i]);
    }
    for(int i =0; i<Res.size();i++){
        cout<<Res[i]<<" ";
    }
    return 0;
}