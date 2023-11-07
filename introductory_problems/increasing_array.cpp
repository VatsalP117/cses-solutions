#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long res=0;
    vector<long> arr;
    for(int i=0;i<n;i++){
        long x;
        cin>>x;
        arr.push_back(x);
    }
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            res+=arr[i-1]-arr[i];
            arr[i]+=(arr[i-1]-arr[i]);
        }
    }
    cout<<res<<endl;
    return 0;
}