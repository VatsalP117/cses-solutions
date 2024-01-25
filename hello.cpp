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


void solve(int n,vector<int>& cities,int m,vector<pi>& queries) {
    vector<int> near(n);
    near[0]=1;
    near[n-1]=n-2;
    for(int i=1;i<=n-2;i++){
        near[i] = (cities[i]-cities[i-1] < cities[i+1]-cities[i]) ? i-1:i+1;
    }

    vector<int> r(n),l(n);
    //r[i]= coins needed to travel to ith city from city 1
    //there to go from a to b (a<b) = r[b]-r[a]
    r[0]=0;
    for(int i=1;i<n;i++){
        if(near[i-1]==i){
            r[i]=r[i-1]+1;
        }
        else{
            r[i]=r[i-1] + (cities[i]-cities[i-1]);
        }
    }
    l[n-1]=0;
    for(int i=n-2;i>=0;i--){
        if(near[i+1]==i){
            l[i]=l[i+1]+1;
        }
        else{
            l[i]=l[i+1]+(cities[i+1]-cities[i]);
        }
    }
    for(auto it:queries){
        int a=it.first;
        int b=it.second;
        a--;
        b--;
        //if a<b , you always move to the right : pay either 1 coin of ax+1 - ax but move right bro
        //similar for a>b always move left
        //now just pre compute this
        if(a<b){
            cout<<r[b]-r[a]<<endl;
        }
        else{
            cout<<l[b]-l[a]<<endl;
        }
    
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin>>tc;
    for (int t = 1; t <= tc; t++) {
        int n;
        cin>>n;
        vector<int> cities(n);
        getInput(cities);
        int m;
        cin>>m;
        vector<pi> queries(m);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            queries[i]={a,b};
        }
        solve(n,cities,m,queries);
    }
}