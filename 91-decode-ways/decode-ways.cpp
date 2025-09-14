class Solution {
public:
    int solve(string &s,int i,vector<int> &dp)
    {
        if(i>=s.size())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int q1 = s[i]-'0';
        int q2 = 0,ans=0;
        if(i<s.size()-1)
        {
            q2=q1*10 + ( s[i+1]-'0' );
        }
        if(q1>0)
            ans+=solve(s,i+1,dp);
        if(q2>0 && q2<=26 && q1>0)
            ans+=solve(s,i+2,dp);
        dp[i]=ans;
        return ans;
    }
    int numDecodings(string s) {
        vector<int>dp(101,-1);
        return solve(s,0,dp);
    }
};