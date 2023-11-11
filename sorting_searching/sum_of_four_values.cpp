//You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int x;
int main() {
	// your code goes here
    cin>>n>>x;
    if(n<4){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<pair<int,int>> arr(n);
    int val;
    for(int i=0;i<n;i++){
       cin>>val;
       arr[i]=make_pair(val,i);
    }
    //start 4 pointer approach but first sort karna padega
    //we are storing index as well to preserve it since we have to return it in ans
	sort(arr.begin(),arr.end());//sorted by values 
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        //now our normal 2 pointer 
	        int reqSum=x-arr[i].first-arr[j].first;
	        int l=j+1;
	        int r=n-1;
	        while(l<r){
	            if(arr[l].first+arr[r].first==reqSum){
	                cout<<arr[i].second+1<<" "<<arr[j].second+1<<" "<<arr[l].second+1<<" "<<arr[r].second+1<<endl;
	                return 0;
	            }
	            else if(arr[l].first+arr[r].first<reqSum){
	                l++;
	            }
	            else r--;
	        }
	    }
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
