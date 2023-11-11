//You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int x;
int main() {
	// your code goes here
    cin>>n>>x;
    if(n<3){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<pair<int,int>> arr(n);
    int val;
    for(int i=0;i<n;i++){
       cin>>val;
       arr[i]=make_pair(val,i);
    }
    //start 3 pointer approach but first sort karna padega
    //we are storing index as well to preserve it since we have to return it in ans
	sort(arr.begin(),arr.end());//sorted by values 
	for(int i=0;i<n;i++){
	    int j=i+1;
	    int k=n-1;
	    //arr[i]+arr[j]+arr[k]=x is needed
	    int reqSum=x-arr[i].first;
	    while(j<k){
	        if(arr[j].first+arr[k].first==reqSum){
	            cout<<arr[i].second+1<<" "<<arr[j].second+1<<" "<<arr[k].second+1<<endl;
	            //just converting to 1 based indexing
	            return 0;
	        }
	        else if(arr[j].first+arr[k].first<reqSum){
	            j++;
	        }
	        else k--;
	    }
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
