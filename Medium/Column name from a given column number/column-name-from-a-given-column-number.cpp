//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans="";
        char mapping[26]={'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
        while(n){
            
            int rem = n%26;
            ans=ans+mapping[rem];
            if(rem==0){
                n=(n/26)-1;
            }
            else
                n=n/26;
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }   
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends