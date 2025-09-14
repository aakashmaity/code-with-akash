class Solution {
public:

    bool solve(vector<int>& nums,int pos,int n,vector<int>&dp)
    {
        if(pos==n)
            return true;
        // if(pos>n)
        //     return false;
        
        if(dp[pos]!= -1)
            return dp[pos];

        for(int i=1;i<=nums[pos];i++)
        {
            if(solve(nums,pos+i,n,dp))
            {
                // dp[pos]= true;
                return true;
            }
        }   
        return dp[pos]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int> dp(n+1,-1);
        return solve(nums,0,n,dp);
    }
};