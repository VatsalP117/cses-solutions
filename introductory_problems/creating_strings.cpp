#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(int ind,string &temp,vector<int> &freq,set<string> &s,int n){
    //base lite
    if(ind==n){
        s.insert(temp);
        return;
    }
    //now try putting every character on this index
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            temp+=i+'a';
            freq[i]--;
            solve(ind+1,temp,freq,s,n);
            temp.pop_back();
            freq[i]++;
        }
    }
}
int main(){
    string str;
    cin>>str;
    set<string> s;
    vector<int> freq(26,0);
    for(char ch:str){
        freq[ch-'a']++;
    }
    string temp="";
    solve(0,temp,freq,s,str.size());
    cout<<s.size()<<endl;
    for(auto &it:s){
        cout<<it<<endl;
    }
    return 0;

}