#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Let's create a set and a multiset. The set will store the positions of the traffic lights, while the multiset will keep track of the "gaps" between the 
// lights. The multiset keeps expanding because more lights are added, and you just need to print the length of the longest passage without traffic lights
//  after each addition (i.e. the max element of that multiset). This element is the last element by default.

// Note that when placing a new traffic light on the road, that light will split the gap between two adjacent lights into two smaller pieces, 
// so you also have to remove the length of that gap in the multiset and add two new lengths to the multiset
int main(){
    int x,n;
    cin>>x>>n;
    vector<int> lights(n);
    int pos;
    for(int i=0;i<n;i++){
        cin>>pos;
        lights[i]=pos;
    }
    set<int> s;//stores positions of all lights installed or the start and ending of roads
    multiset<int> dist; //stores all intervals
    s.insert(0);
    s.insert(x);
    dist.insert(x);
    for(int l:lights){
        //now split the intervals for each light added
        auto high=s.upper_bound(l);
        auto low=high;
        low--;
        //ye dono ke bich ka interval split kar dega ye gandu
        dist.erase(dist.find(*high-*low));
        //now it will also create two intervals by splitting upar wala usko bas insert kardo
        dist.insert(*high-l);
        dist.insert(l-*low);
        s.insert(l);
        //now print the largest interval/dist
        auto ans=dist.end();
        ans--; //last element will be max
        cout<<*ans<<" ";
    }
    return 0;
}