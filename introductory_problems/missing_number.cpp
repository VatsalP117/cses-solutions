#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long sum=0;
    for(long i=0;i<n-1;i++){
        //take n-1 inputs
        long x;
        cin>>x;
        sum+=x;
    }
    long long expectedSum=0;
    for(long i=1;i<=n;i++){
        expectedSum+=i;
    }
    cout<<expectedSum-sum<<endl;
    return 0;

}