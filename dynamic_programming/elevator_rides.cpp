#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int,int>

const int MOD=1e9+7;

template <typename T>

void getInput(vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
    cin >> v[i];
    }
}

template <typename T>

void sortV(vector<T> &v){
    sort(v.begin(),v.end());
}


void solve() {

}
//INTUTION:
// once we fix the order of people we can easily figure the number of rides right?
// as soon as sum of weights>=x, start a new ride
//so we can check for each permuation: TC=(n*n!)
//but we need a faster approach

//say x=10 and we have people 4 8 6 1
// say we fix 1 at last (in order) and permute 4,8,6
// 4 8 6 | 1 => we will need 3 rides for (4,8,6) and last ride occupancy =6
// 4 6 8 | 1 => will need 2 rides for 4,8,6 and last ride occupancy = 8
// 8 6 4 | 1 => will need 2 rides and last ride occupancy =10
// and so on..
//  and to find number of rides including 1 as well we dont need a lot of info
//  we just want to know the number of rides before and occupancy of last ride
// for say subset 4,8,6 we dont care about which order they went, all we care about is the number of rides they took and last ride occupancy
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int> weights(n);
    getInput(weights);
    vector<pi> dp((1<<n),{1e9,1e9});
    //stores for each subset S (rides(S),last(S))
    dp[0]={1,0};//empty subset
    //iterate over all subsets
    for(int s=1;s<(1<<n);s++){
        //in this subset to find best case 
        //try each city in this subset ast last postion in order (how we gave our example)
        for(int p=1;p<=n;p++){
            //if p is included in this subset or not
            if(s & (1<<(p-1))){
                //try this dude at last place
                auto [rides,lastWeight]=dp[s ^ (1<<(p-1))];//find best case scenario with everyone expect this dude
                
                if(lastWeight + weights[p-1]>x){
                    rides++;
                    lastWeight=weights[p-1];
                }
                else{
                    lastWeight+=weights[p-1];
                }
                dp[s]=min(dp[s],{rides,lastWeight});
            }
            //varna lite bhai
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;
    return 0;
}