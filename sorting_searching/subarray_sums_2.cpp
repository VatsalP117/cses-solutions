// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    long long sum=0;
    unordered_map<long long,long long> m;
    m[0]=1;
    long long res=0;
    //   *If there is a subarray with a prefix sum of prefix_sum - X,
	// 	 * we can exclude it from our current subarray to get the desired sum.
	// 	 * Thus, we can add the number of those subarrays to our answer.
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        res+=m[sum-x];
        m[sum]++;
    }
    cout<<res<<endl;
    return 0;
}