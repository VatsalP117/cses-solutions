#include <iostream>
#include <vector>
using namespace std;
//n sirf <=20 islie recursion chal jayega
void solve(long ind,long long curr,long long totSum,vector<long> &arr,long long &ans){
    //base lite
    if(ind<0){
        ans=min(ans,abs(totSum-curr-curr));
        //totSum-curr is the sum of elements we have not picked i.e the other group
        return;
    }

    //take
    solve(ind-1,curr+arr[ind],totSum,arr,ans);
    //not take
    solve(ind-1,curr,totSum,arr,ans);
}
int main(){
    int n;
    cin>>n;
    vector<long> arr;
    long x;
    long long totSum=0;
    for(int i=0;i<n;i++){
        cin>>x;
        totSum+=x;
        arr.push_back(x);
    }
    long long ans=1e9;
    solve(n-1,0,totSum,arr,ans);
    cout<<ans<<endl;
    return 0;

}