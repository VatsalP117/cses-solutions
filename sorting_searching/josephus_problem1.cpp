#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	std::deque<int> dq ;
	for(int i=2;i<=n;i++){
	    dq.push_back(i);
	}
	dq.push_back(1);
	while(dq.size()>=2){
	    int first_ele=dq.front();//ye udega bichara
	    cout<<first_ele<<" ";
	    dq.pop_front();
	    //aur iske baad wala bach gya bc kyuki alternate hai to isko ab vapas line mai sabse piche daal do 
	    int second_ele=dq.front();
	    dq.pop_front();
	    dq.push_back(second_ele);
	}
	if(dq.empty()==false){
	    cout<<dq.front()<<endl;
	}
	return 0;
}
