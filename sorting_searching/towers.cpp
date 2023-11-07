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
    multiset<int> s;
    int res=0;
    for(int i=0;i<n;i++){
        auto it=s.upper_bound(arr[i]);
        if(it==s.end()){
            //means no bigger element yet jispe upar join kar sakte
            //lets just create our own then
            res++;
            s.insert(arr[i]);
        }
        else{
            //join this brother
            s.erase(it);
            s.insert(arr[i]);
            //since prev element is no longer the top now , our curr element is at top to bas utna set mai modofy kar diya
        }
    }
    cout<<res<<endl;
    return 0;

}