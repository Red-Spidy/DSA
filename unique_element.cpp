#include<iostream>
#include <vector>
using namespace std;
int Unique(vector <int> arr){
    int ans=0;
    for(int  i =0; i<arr.size(); i++){
        ans= ans^arr[i];
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Size Of the Array";
    cin>>n;
    vector<int>arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int unique = Unique(arr);
    cout<<unique;
    return 0;
}