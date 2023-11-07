//optimal solution (not my usual sliding window wala approach on this)
// The approach stores the last indexes of already visited characters. The idea is to traverse the string from left to right,
//  for each character at index j, update the i pointer(starting index of current window) to be the maximum of its current value and last Index of str[j] + 1.
//   This step ensures that i is moved to the appropriate position to exclude any repeating characters within the new window.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
    }
    int res=0;
    int i=0;
    int j=0;
    map<int,int> m;//stores last index jispe koi value mili h abhi tak
    while(j<n){
        //adjust i accordingly
        if(m.find(arr[j])!=m.end()){
            i=max(i,m[arr[j]]+1);
        }
        
        res=max(res,j-i+1);
        m[arr[j]]=j;
        j++;
    }
    cout<<res<<endl;
    return 0;
}


//usual approach
// the question is just longest subarr without repeating element
//tle on last case idk isse efficent kya hoga
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr;
//     int x;
//     for(int i=0;i<n;i++){
//         cin>>x;
//         arr.push_back(x);
//     }
//     //now apply sliding window
//     unordered_set<int> s;
//     int i=0;
//     int j=0;
//     int res=0;
//     while(j<n){
//         if(s.find(arr[j])!=s.end()){
//             //means duplicates found
//             while(s.find(arr[j])!=s.end()){
//                 s.erase(arr[i]);
//                 i++;
//             }
//         }
//         s.insert(arr[j]);
//         res=max(res,j-i+1);
//         j++;
//     }
//     cout<<res<<endl;
//     return 0;
// }