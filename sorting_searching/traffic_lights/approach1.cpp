#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// We'll start by trying to find the maximum gap once all the traffic lights are added. This is the last number we'll output,
//  so we'll add it to the end of our output array. Then, we'll remove traffic lights in the reverse order to how they were added, 
//  and find the gap each removal creates.
// This gap is just the distance between the two street coordinates (either a traffic light or the beginning or ending of the street) n
// ext to a given traffic light stored in our set, so we can use our set to find these values and subtract them to get our gap.

// But this gap may not be the maximum gap. We'll compare this to the gap we found once all the traffic lights are added, and set 
// the max gap to the greater value. We'll then set the next lowest element in the output array to this value, which will represent the
//  greatest gap prior to adding the traffic light we just removed.
int main(){
    int x,n;
    cin>>x>>n;
    vector<int> lights(n);
    int pos;
    for(int i=0;i<n;i++){
        cin>>pos;
        lights[i]=pos;
    }
    //find the max gap after all lights are installed, this will be our last value in ans
    vector<int> ans(n);
    set<int> s;
    s.insert(0);
    s.insert(x);
    for(auto it:lights){
        s.insert(it);
    }
    int max_gap=0;
    int prev=0;
    for(int it:s){
        max_gap=max(max_gap,it-prev);
        prev=it;
    }
    
    ans[n-1]=max_gap;
    //now start removing lights from back and see the gap it creates
    
    for(int i=n-1;i>0;i--){
        s.erase(lights[i]);
        auto high_it=s.upper_bound(lights[i]);
        int high=*high_it;
        
        int low=*(--high_it);
        max_gap=max(max_gap,high-low);
        ans[i-1]=max_gap;
        
    }
    for(int a:ans){
        cout<<a<<" ";
    }
    return 0;

}