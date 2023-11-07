
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Optimal Approach: O(nlogn)
// Using binary search
// Basic idea:
// eg : arr= 2 5 3 7 11 9 10 13 6
//     smallest milate jao large banate jao (solving smaller subproblems first)
//     lis=2 (pehle 2 aaya)
//     lis= 2 5
//     now 3 aaya
//     3 cannot extend this lis but we can replace 5 with 3 right?
//     Why tho? Length of lis would still be the same currently and if aage 4 aaya to vo apne join kar sakta h na if last mai 3 hai . 5 hua to nahi kar paya
//     islie isme apna fayda hi hai
        // which number to replace tho? replace the number i.e just higher than 9 i.e upperbound (yaha to sidha 11 hai par bade cases mai kaam aayega)
//     so lis= 2 3

//     now comes 7
//     lis=2 3 7
//     lis=2 3 7 11

//     now comes 9, again suma funda upar wala it will replace 9
//     lis=2 3 7 9
//     lis= 2 3 7 9 10
//     lis= 2 3 7 9 10 13
        // now comes 6, it will replace just higher i.e 7 (kya use hai iska? aage jaake kaam aa sakta h in some cases and anyway length kam to nahi hui to we dk)
        // lis=2 3 6 9 10 13
        // this lis we get is not the real lis since order kuch bhi hoga par length se matlab h na vo sahi hoga
//     so final ans=6

//in this method, length will never reduce by any incoming value, it will either stay same or increase
//if we get some smaller value, we will replace and it will help to maintain pehle ka part
//larger value will help to increase the lis


//Implementation 1: using set
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n; //number of coins
    cin>>n;
    vector<int> arr(n);
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
    }
    set<int> s;
    for(int i=0;i<n;i++){
        if(s.find(arr[i])!=s.end())continue;
        auto it=s.upper_bound(arr[i]);
        if(it==s.end()){
            s.insert(arr[i]);
        }
        else{
            s.erase(it);
            s.insert(arr[i]);
        }
    }
    cout<<s.size()<<endl;
    return 0;
}

//Implementation 2: using vector only
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n; //number of coins
    cin>>n;
    vector<int> arr(n);
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
    }
    vector<int> lis;
    lis.push_back(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]>lis.back()){
            lis.push_back(arr[i]);
        }
        else{
            //index to replace will be found using lower_bound method
            int ind=lower_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
            lis[ind]=arr[i];
        }
    }
    cout<<lis.size()<<endl;
    return 0;
}