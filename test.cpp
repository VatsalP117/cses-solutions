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


void solve(int n,int m,vector<int> &cities,vector<pi>&queries,vector<int> &near) {
    for(auto it:queries){
        int a=it.first;
        int b=it.second;
        a--;
        b--;
        if(a<b){
            int coins=0;
            int node=a;
            while(near[node]>node){
                if(near[node]==b){
                     coins++;
                     cout<<coins<<endl;
                     break;
                }
                coins++;
                node=near[node];
            }
            if(coins!=1){
                coins+=(cities[b]-cities[node]);
            cout<<coins<<endl;
            }
            
        }
        else{
            cout<<"TBD"<<endl;
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
            int x,y;
            cin>>x>>y;
            queries[i]={x,y};
        }
        vector<int> near(n);
        near[0]=1;
        near[n-1]=n-2;
        for(int i=1;i<n-1;i++){
            near[i]= ((cities[i+1]-cities[i]>cities[i]-cities[i-1]) ? i-1:i+1); 
        }
        solve(n,m,cities,queries,near);
    }
}