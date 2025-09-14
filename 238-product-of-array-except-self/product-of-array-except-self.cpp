class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        int rightmul=1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=rightmul;
            rightmul*=nums[i];
        }

        int leftmul=1;
        for(int i=0;i<n;i++)
        {
            ans[i]*=leftmul;
            leftmul*=nums[i];
        }

        // for(auto i :ans)
        //     cout<<i<<" ";
        return ans;
    }
};