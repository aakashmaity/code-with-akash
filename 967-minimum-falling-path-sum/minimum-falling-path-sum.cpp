class Solution {
public:
    int M = 1e9 + 7;
    int solve(vector<vector<int>>& matrix,int i,int j,int n,vector<vector<int>> &dp)
    {
        if(i==n-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=M)
            return dp[i][j];

        int mini=solve(matrix,i+1,j,n,dp);
        if(j>0)
            mini=min( mini, solve(matrix,i+1,j-1,n,dp) );
        if(j<n-1)
            mini=min( mini, solve(matrix,i+1,j+1,n,dp) );
        int res= matrix[i][j] + mini;

        dp[i][j]=res;
        return res;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,M));
        int ans=M;
        for(int j=0;j<n;j++)
        {
            ans = min(ans,solve(matrix,0,j,n,dp));
        }
        return ans;
    }
};