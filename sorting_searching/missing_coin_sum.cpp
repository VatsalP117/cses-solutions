#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> coins;
    int c;
    for(int i=0;i<n;i++){
        cin>>c;
        coins.push_back(c);
    }
    sort(coins.begin(),coins.end());
    long long sum=0; //we are always looking for sum+1 as our potential ans
    for(int i=0;i<n;i++){
         //sum+1 is the sum we are now trying to achieve
        if(coins[i]>(sum+1)){
            //say you were looking for 4 and got 10
            //to there is a gap to bichke numbers nahi bann payenge
            break;
        }
        if((sum+1)==coins[i]){
           //jo dekh rahe the sidha wahi mil gya to lite
            sum+=coins[i];
        }
        else if(sum+1>coins[i]){
            //you could aldready create all values till sum
            //now you get a new value isse gap to nahi bani
            //you can create sum+1 using exisiting values aur ye
            sum+=coins[i];
        }
        
    }
    cout<<sum+1<<endl;
    return 0;
}