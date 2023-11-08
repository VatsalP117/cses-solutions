#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(int a,int b){
    //1st condition is  (assume b>=a) then b<=2a
    //why? is b>2a then har ek baar b mai se 2 le a maise 1 fir bhi a khatam ho jayega and b bach jayega 
    //next
    //we have 2 operations : 
    //first is 2 , 1 i.e remove 2 from 1st pile(a) and 1 from 2nd pile(b)
    //second is 1 , 2 i.e remove 1 from a and 2 from b 
    //assume 1st operation is done x times and 2nd operation is done y times 
    //a = 2x + y ; b= x + 2y
    //a+b = 3(x+y)
    //x+y=total number of operations = (a+b)/3
    //so a+b must be a multiple of 3 and b<=2a if both true then output yes
    if(a>b){
        swap(a,b);
    }
    //b is always greater
    if(b<=2*a && (a+b)%3==0){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	int a,b;
	while(t--){
	    cin>>a>>b;
	    solve(a,b);
	}
	return 0;
}
