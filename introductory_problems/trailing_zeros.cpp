#include <iostream>
using namespace std;

int main(){
    //number of zeros = number of 5's (since 5*2 dega 0 and we assume 2 to honge kaafi to num of 5 will determine this)
    //General equation to the find the power of any number in the some other number
    // (x^y)*k= n!
    //n! is the number jisme power nikalna hai, x is the number jiska power nikalna hai
    //so here its (5^y)*k=n!
    //how to count that? simply take the floor of n/5
    //eg 11!= 1*2..5*..10*11 to isme 5 do baar aayenge in 5 and 10 (=11/5)
    //by taking floor of n/5 we will get one 5, for getting the remaining 5 in a number (say 25 contributes 2 5's), divided n/5 again by 5 then take floor
    long n;
    cin>>n;
    long long res=0;
    while(n!=0){
        res+=n/5;
        n=n/5;
    }
    cout<<res<<endl;
    // T.c = O(log(n)) (base of log =5)
    return 0;
}