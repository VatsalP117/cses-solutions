#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n;
    cin>>m;
    cin>>k;
    vector<int> desire;
    vector<int> apt;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        desire.push_back(a);
    }
    for(int i=0;i<m;i++){
        cin>>a;
        apt.push_back(a);
    }
    sort(desire.begin(),desire.end());
    sort(apt.begin(),apt.end());
    //idea try giving the smallest apt to the least desire wala banda
    //kyuki usne hi nahi liya to baaki koi to usko pakka nahi lene wala lmao
    int res=0;
    int i=0;
    int j=0;
    while(i<n && j<m){
        //i-> desire, j->apt
        //3 cases possible: conditions met, apt too small, apt too big
        if(abs(desire[i]-apt[j])<=k){
            i++;
            j++;
            res++;
        }
        else if(apt[j]<desire[i]){
            //means apt isko chota pad gya next apt dikhao zara
            j++;
        }
        else{
            //apt zyada bada hai
            //to next isse zyada desire wala banda lao
            i++;
        }
    }
    cout<<res<<endl;
    return 0;
}