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
    int tc = 1;
    cin>>tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}