#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arrive;
    vector<int> depart;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>b;
        arrive.push_back(a);
        depart.push_back(b);
    }
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    int i=0;
    int j=0;
    int curr=0;
    int res=0;
    while(i<n && j<n){
        if(arrive[i]<depart[j]){
            //someone has arrived
            curr++;
            i++;
        }
        else if(depart[j]<arrive[i]){
            curr--;
            j++;
        }
        else{
            i++;
            j++;
        }
        res=max(res,curr);
    }
    cout<<res<<endl;
    return 0;
}