class Solution {
public:
    int dp[101];
    int solve(int i, vector<int> &nums,int dp[]){
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        // dont take
        int dont = solve(i+1,nums,dp);
        int take = nums[i] + solve(i+2,nums,dp);

        return dp[i] = max(dont,take);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,dp);
    }
};