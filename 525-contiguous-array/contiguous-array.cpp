class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                sum+=1;
            else
                sum-=1;
            
            if(sum==0)
            {
                if(ans < i+1)
                    ans=i+1;
            }
            else if(mp.find(sum)!=mp.end())
            {
                if(ans < i-mp[sum])
                    ans=i-mp[sum];
            }
            else
                mp[sum]=i;
        }
        return ans;
    }
};