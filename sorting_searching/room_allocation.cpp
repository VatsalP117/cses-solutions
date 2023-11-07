#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// we can iterate through the customers while maintaining a minimum priority queue that stores the departure times of customers we've already processed.
//  For each customer, we check to see if the minimum element in the priority queue is less than the arrival time of the new customer.
int main(){
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> cust;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cust.push_back({a,{b,i}});
    }
    sort(cust.begin(),cust.end());
    //cust stores {arrival,{departure,og index since array sab sort ho gaye}}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //stores {kab_free_hoga,room number}
    int rooms=0;
    int last_room=0;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int arrive=cust[i].first;
        int dept=cust[i].second.first;
        int index=cust[i].second.second;
        if(pq.empty()){
            //means room reuse nahi hoga ek naya banana padega
            last_room++;
            pq.push({dept,last_room});
            ans[index]=last_room;
        }
        else{
            auto it=pq.top();
            //check ye wala room available hai abhi ya nahi
            if(it.first<arrive){
                pq.pop();
                pq.push({dept,it.second});
                ans[index]=it.second;
            }
            else{
                //cannot reuse this room to naya banana padega
                //same code as pq.empty() wala block bas code ka intuition samjh aaye islie alag likha h
                 last_room++;
                pq.push({dept,last_room});
                ans[index]=last_room;
            }
        }
        rooms = max(rooms, int(pq.size()));
    }
    cout<<rooms<<endl;
    for(int a:ans){
        cout<<a<<" ";
    }
    return 0;
}