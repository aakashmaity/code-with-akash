class Solution {
public:
    int solve(vector<int>& nums,int i,int limit,vector<int> &dp)
    {
        if(i>limit)
            return 0;
        if(dp[i]!=-1)
            return dp[i];

        int steal = nums[i] + solve(nums,i+2,limit,dp);
        int skip = solve(nums,i+1,limit,dp);
        
        dp[i]=max(steal,skip);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int case1 = solve(nums,0,n-2,dp1);
        int case2 = solve(nums,1,n-1,dp2);
        
        return max(case1,case2);
    }
};