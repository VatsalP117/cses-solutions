#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
static bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}
int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	vector<pair<int,int>> movies(n);
	int a,b;
	for(int i=0;i<n;i++){
	    cin>>a>>b;
	    movies[i]=MP(a,b);
	}
	sort(movies.begin(),movies.end(),cmp);//sorted by end times
	int res=0;
	multiset<int> end_times;//set mai sabke end times daalne hai
	for (int i = 0; i < k; ++i) end_times.insert(0); //for k guys

	//atleast k movies to dekh hi lenge sab 
	for(int i=0;i<n;i++){
	    int start=movies[i].first;
	    int end=movies[i].second;
	    //now we have to find a guy jiska movie apne start ke pehle end hua
	    //so upper bound nikal ke it--
	    auto it=end_times.upper_bound(start);
	    if(it==end_times.begin()){
	        continue;
	    }
	    it--;
	    end_times.erase(it);
	    end_times.insert(end);
	    res++;
	}
	cout<<res<<endl;
	return 0;
}
