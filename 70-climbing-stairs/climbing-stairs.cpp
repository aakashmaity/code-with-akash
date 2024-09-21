class Solution {
public:
    int solve(int curr,int dp[]){
        if(curr == 0){
            return 1;
        }
        if(curr < 0){
            return 0;
        }
        if(dp[curr] != -1){
            return dp[curr];
        }

        int ways = solve(curr-1,dp) + solve(curr-2,dp);
        
        return dp[curr] = ways;
    }
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        
        return solve(n,dp);
    }
};