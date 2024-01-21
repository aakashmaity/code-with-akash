class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        if(n==3)
        {
            int p=nums[0]+nums[2];
            return max(nums[1],p);
        }

        dp[n-1]=nums[n-1];
        dp[n-2]=nums[n-2];
        dp[n-3]=nums[n-3]+nums[n-1];

        for(int i=n-4;i>=0;i--)
        {
            int res=nums[i]+ max(dp[i+2],dp[i+3]);
            dp[i]=res;
        }
        return max(dp[0],dp[1]);
    }
};