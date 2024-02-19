class Solution {
public:
    void solve(int n,vector<int>&dp)
    {
        int cnt=0;
        int k=n;
        while(n)
        {
            if(dp[n]!=-1)
            {
                cnt+=dp[n];
            }    
            if(n&1)
                cnt++;
            n=n>>1;
        }
        dp[k]=cnt;
    }
    vector<int> countBits(int n) {
        vector<int>dp(n+1,-1);
        for(int i=n;i>=0;i--)
            solve(i,dp);
        return dp;
    }
};