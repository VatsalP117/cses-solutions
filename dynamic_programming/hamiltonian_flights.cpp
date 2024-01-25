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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[b].push_back(a);
    }
    //dp with bitmask
    //dp[S][i]= number of routes that visit all cities in the set S and end at city i
    //we can use an integer bit mask to store set S
    //since n cities to S can be 0 to 1<<n
    vector<vector<int>> dp(1<<n,vector<int>(n+1,0));
    dp[1][1]=1;//only 1 way to reach city 1 starting from city 1
    //final ans is dp[(1<<n) -1][n]= routes flying to all cities and ending at city n
    //iterate over all subsets now
    for(int s=2;s<(1<<n);s++){
        //only consider those subsets that have the first city
        if((s&1)==0)continue;
        //also make sure you only consider those jisme nth city isnt consider before only varna maza nahi aayega
       if ((s & (1 << (n - 1))) && (s != ((1 << n) - 1))) 
{
            continue;
            //i.e if you have visited the nth city already and its not a full subset, this set is of no use to us
        }
        //now consider each city
        for(int city=1;city<=n;city++){
            if((s & (1<<(city-1)))==0){
                //agar set mai apna city ko include hi nahi kiya hai to lite lo na bhai
                continue;
            }
            // dp[s | (1<<(city-1))][city]=0;
            //add all the paths ending at city x where x is an adj node of our city
            for(int adjCity:adj[city]){
                if(s & (1<<(adjCity-1))){
                    dp[s][city]+=dp[s^(1<<(city-1))][adjCity];
                    dp[s][city]%=MOD;
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n]<<endl;
    return 0;
}