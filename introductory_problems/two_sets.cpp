#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Algo: greedy approach
// If total sum is not even, you cant divide it onto 2 equal sums, so sidha return NO
// if it is even, we can divide it

// Greedily, start with the largest number (i.e n), if it is less than the requiredSum, add it to our set1 and decreae requiredSum by that number.
// otherwise add to set2. 
// why this?
// you are starting from biggest number and going down, so if you take that number, requiredSum would bacha hua would need someone <currNum aage jaake since required is reducing every time
// and you know chote number to available hai hi since you started from back
// eg: if req sum=11 and you currently at num 7, you take it so required=4. you can be sure to get required since you know 4 would be surely available with us
int main(){
    long n;
    cin>>n;
    long long totSum=n*(n+1)/2;
    if(totSum%2==1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    set<int> s1,s2;
    long long reqSum=totSum/2;
    for(int i=n;i>=1;i--){
        if(i<=reqSum){
            s1.insert(i);
            reqSum-=i;
        }
        else{
            s2.insert(i);        }
    }
    cout<<s1.size()<<endl;
    for(auto it:s1){
        cout<<it<<" ";
    }
    cout<<endl;
     cout<<s2.size()<<endl;
    for(auto it:s2){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;

    
}