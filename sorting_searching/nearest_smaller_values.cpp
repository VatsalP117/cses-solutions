#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//question is to find nearest smaller on left lol (uska index print karna h)
//also its 1 -based indexing
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	stack<int> st;
	for(int i=0;i<n;i++){
	    while(st.empty()==false && arr[st.top()]>=arr[i]){
	        st.pop();
	    }
	    if(st.empty()){
	        //means no smaller on left found
	        cout<<0<<" ";
	    }
	    else{
	        cout<<st.top()+1<<" ";//just converting index to 1-based
	    }
	    st.push(i);
	}
	return 0;
}
