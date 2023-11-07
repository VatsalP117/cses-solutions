#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    map<int,int> tickets;
    vector<int> cust;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        tickets[x]++;
    }
    for(int i=0;i<m;i++){
        cin>>x;
        cust.push_back(x);
    }
    //tickets has also the tickets as {price_of_ticket,num_available}

    for(int i=0;i<m;i++){
        auto it=tickets.lower_bound(cust[i]);
        //it would point to the iterator with ticket price just greater or equal to customers limit

       if(it==tickets.end()){
        //means saari tickets ya to sasti hai is customer keliye ya fir no tickets availavle
        //in first case, we reach end()-1 means maximum possible price of ticket (since saari hi affordable hai is bande ke liye)
            if(tickets.empty()){
                cout<<-1<<endl;
            }
            else{
                it--;
                cout<<(it->first)<<endl;
                it->second--;
                if(it->second==0){
                    tickets.erase(it);
                }
            }
        }

        else{
            //it ka ticket mehenga h apne liye
            //islie find the first ticket that is in our budget
            while(it!=tickets.begin() && it->first>cust[i]){
                it--;
            }
            if(it->first<=cust[i]){
                cout<<(it->first)<<endl;
                it->second--;
            if(it->second==0){
                tickets.erase(it);
            }

            }
            else{
                cout<<-1<<endl;
            }
        }
    }
    
    return 0;
}