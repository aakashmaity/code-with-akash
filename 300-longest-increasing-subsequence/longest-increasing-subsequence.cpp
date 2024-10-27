class Solution {
public:
    int solve(int i, int prev_idx, vector<int> &nums, vector<vector<int>>&dp ,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i][prev_idx + 1] != -1){
            return dp[i][prev_idx + 1];
        }

        int take = solve(i+1,prev_idx,nums,dp,n);

        int dontTake;
        if(prev_idx == -1 || nums[i] > nums[prev_idx]){
            dontTake = 1 + solve(i+1,i,nums,dp,n);
        }
        
        return dp[i][prev_idx + 1] = max(take,dontTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp,n);
    }
};