#include <iostream>
using namespace std;
void solve(int k){
    if(k>=1 && k<=9){
        cout<<k<<endl;
    }
    
}
int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        solve(k);
    }
    return 0;
}