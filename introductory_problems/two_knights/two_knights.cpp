#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll n){
    //total ways is just n C 2
    ll totalWays=((n*n)*(n*n-1))/2;
    //ll waysToAttack = (2*(n-1)*(n-2)) + (2*(n-1)*(n-2));
    //just simplify above formula 
    ll waysToAttack= 4*(n-1)*(n-2);
    return totalWays-waysToAttack;
}
int main() {
	// your code goes here
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
	    cout<<solve(i)<<endl;
	}
	return 0;
}
