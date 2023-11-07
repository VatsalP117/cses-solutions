#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Approach:
// Surprisingly, the optimal solution to the problem does not depend on the
// deadlines at all, but a correct greedy strategy is to simply perform the tasks
// sorted by their durations in increasing order. The reason for this is that if we
// ever perform two tasks one after another such that the first task takes longer
// than the second task, we can obtain a better solution if we swap the tasks.
int main(){
    int n;
    cin>>n;
    int a,b;
    vector<pair<int,int>> tasks;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        tasks.push_back({a,b});
    }
    sort(tasks.begin(),tasks.end());
    //sorted by duration , jo sabse chota vo sabse pehla
    long long currTime=0;
    long long res=0;
    for(auto it:tasks){
        currTime+=it.first; //time increased by duration of tasks
        res+=(it.second-currTime);
    }
    cout<<res<<endl;
    return 0;


}