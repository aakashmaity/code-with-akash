class Solution {
public:
    int solve(vector<int>nums,int i,int n,vector<int>& dp)
    {
        if(i>n-1)
            return 0;
        if(i==n-1)
            return nums[i];

        if(dp[i]!=-1)
            return dp[i];

        int res=0;
        int j=i+2;
        while(j<n)
        {
            res =  max(res,solve(nums,j,n,dp));
            j++;
        }
        res+=nums[i];
        dp[i]=res;
        cout<<dp[i]<<" ";
        return res;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int i=0,ans=0;
        while(i<n)
        {
            ans=max(ans,solve(nums,i,n,dp));
            i++;
        } 
        return ans;
    }
};