#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<long long> &machines,long long totalTime,long long reqProducts){
    long long products=0;
    for(long long i=0;i<machines.size();i++){
        products+=(totalTime/machines[i]);
        if(products>=reqProducts) return true;
    }
    return false;
}
int main() {
	// your code goes here
	long long n,t;
	cin>>n>>t;
	//n= number of machines
	//t=total products
	vector<long long> machines(n);
	long long mini=INT_MAX;
	long long maxi=INT_MIN;

	for(long long i=0;i<n;i++){
	    cin>>machines[i];
	    mini=min(mini,machines[i]);
	    maxi=max(maxi,machines[i]);
	}
	//maxi => slowest machine ka time to make one product 
	//mini => fastest machine ka time to make one product 
    //ideally it should be (acc to me ofc)
    // long long low=(mini*t)/n -1;
	// long long high=(maxi*t)/n + 1;
    //but isse bhot bade cases mai kuch bt aa rahi to lets go with 1 and 1e18
	long long low=1; 
	long long high=1e18;

	long long ans=high;
	while(low<=high){
	    long long  mid=(low + (high-low)/2);
	    if(isPossible(machines,mid,t)){
	        //means mid total time mai to ban sakta h 
	        //par lets try isse kam mai ban sakta kya?
	        ans=mid;
	        high=mid-1;
	    }
	    else{
	        //need more time fellas
	        low=mid+1;
	    }
	}

	cout<<ans<<endl;
	return 0;
}
