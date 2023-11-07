#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long n,x;
    cin>>n;
    cin>>x;
    vector<long> arr;
    long weight;
    for(long i=0;i<n;i++){
        cin>>weight;
        arr.push_back(weight);
    }
    sort(arr.begin(),arr.end());
    //idea is try topair the heaviest(j) with lighest(i)
    //if they cant be paired, means the heaviest cannot be paired with anyone else and usko aag se de do ek (j-- and res++)
    
    long res=0;
    long i=0;
    long j=n-1;
    while(i<=j){
       
        if(arr[i]+arr[j]>x){
            //arr[j] coul not be clubbed with even the smallest child fir ye to kisi se nahi hone wala
            //so aise jitne bhi hai sabko khudka alag gondola de do bas
            while(arr[i]+arr[j]>x && i!=j){
                res++;
                j--;
            } 
        }
        //now this element can be clubbed with us so just one gondola combined to both of them
        res++;
        i++;
        j--;
    }
    cout<<res<<endl;
    return 0;
}