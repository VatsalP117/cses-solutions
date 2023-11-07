#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr,long long maxi,long long k){
    long long res=1;
    long long curr=0;
    for(long long i=0;i<arr.size();i++){
        if(arr[i]>maxi) return false;
        if(curr+arr[i]>maxi){
            res++;
            curr=0;
        }
        curr+=arr[i];
        if(res>k) return false;
    }
    return true;
}
int main() {
	// your code goes here
	long long n;
	long long k;
	cin>>n>>k;
	vector<int> arr(n);
	long long sum=0;
	for(long long i=0;i<n;i++){
	    cin>>arr[i];
	    sum+=arr[i];
	}
	//now binary search 
	//max sum in a subarray can be atmax the total sum aur min =1 
	long long low=1;
	long long high=sum;
	long long ans=high;
	while(low<=high){
	    long long mid=(low+high)/2;
	    if(isPossible(arr,mid,k)){
	        //try isse bhi kam mil sakta kya
	        ans=mid;
	        high=mid-1;
	    }
	    else{
	        low=mid+1;
	    }
	}
	cout<<ans<<endl;
	return 0;
}
