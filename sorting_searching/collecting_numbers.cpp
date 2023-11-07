#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int res=0;
    unordered_set<int> s;
    
    for(int i=0;i<n;i++){
        if(s.find(arr[i]-1)==s.end()){
            //arr[i]-1 aana chaiye tha pehle lekin ye aaya baadme hai 
            //means iske liye ek alag se round karna padega
            //kyu? iske pehle ka element abhi tk aaya nahi left mai to
            //to vo pick ho jaye fir hi isko le sakte to ek alag round lagega
            res++;
        }
        // else{
        //     ye element ki bakchodi would not lead to an extra round
        // }
        s.insert(arr[i]);
    }
    cout<<res<<endl;
}