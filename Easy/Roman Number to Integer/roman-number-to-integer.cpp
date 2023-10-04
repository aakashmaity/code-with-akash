//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        int ans=0;
        int n=str.length();
        unordered_map<char,int> mp ={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        
        if(n==1){
            return mp[str[0]];
        }
        
        for(int i=0;i<=n-2;i++){
            if(mp[str[i+1]]>mp[str[i]]){
                ans+=mp[str[i+1]]-mp[str[i]];
                i++;
                if(i==n-1){
                    return ans;
                }
            }
            else{
                ans+=mp[str[i]];
            }
        }
        ans+=mp[str[n-1]];
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends