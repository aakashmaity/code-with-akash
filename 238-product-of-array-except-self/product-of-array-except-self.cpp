class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int cntzero=0,idx,mul=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                cntzero++;
                if(cntzero>=2)
                    return ans;
                idx=i;
            }
            else 
                mul*=nums[i];
        }
        if(cntzero)
        {
            ans[idx]=mul;
            return ans;
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=mul/nums[i];
        }
        return ans;
    }
};