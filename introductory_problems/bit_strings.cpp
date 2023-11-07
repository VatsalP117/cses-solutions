#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long n;
    cin>>n;
    long long res=1;
    int mod=1e9+7;
    //apne ko chaiye to pow(2,n) lekin bhot badi values mai bt de raha tha
    //islie we are left shifting n times => equivalent to 2 ka power lena n times
    while(n>0){
        res=res<<1;
        res=res%mod;
        n--;
    }
    cout<<res<<endl;

    return 0;
}