class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int ans=n;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==val)
            {
                nums[i]=INT_MAX;
                ans-=1;
            }
        }
        sort(nums.begin(),nums.end());
        return ans;
    }
};