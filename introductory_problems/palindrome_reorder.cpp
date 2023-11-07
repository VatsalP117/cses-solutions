#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Idea is for it be a palindrome, there can be atmost one char jiska frequency odd hai since usko  bich mai daal denge to maamla set
// usse zyada hai to bt hoga
int main(){
    string str;
    cin>>str;
    vector<int> freq(26,0);
    for(char ch:str){
        freq[ch-'A']++;
    }
    int odd=0;
    string oddChars="";
    for(int i=0;i<26;i++){
        if(freq[i]%2==1){
            odd++;
            oddChars=string(freq[i],i+'A');
            freq[i]=0;
        }
    }
    if(odd>1){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    string first="";
    string last="";
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            first+=string(freq[i]/2,i+'A');
            last+=string(freq[i]/2,i+'A');

        }
    }
    reverse(last.begin(),last.end());
    cout<<first+oddChars+last<<endl;
    return 0;

}