#include <iostream>
using namespace std;
int main(){
    string str;
    cin>>str;
    char currCh=str[0];
    int currLen=1;
    int res=1;
    for(int i=1;i<str.size();i++){
        if(str[i]==currCh){
            currLen++;
        }
        else{
            res=max(res,currLen);
            currLen=1;
            currCh=str[i];
        }
    }
    res=max(res,currLen);
    cout<<res<<endl;
    return 0;
    
}