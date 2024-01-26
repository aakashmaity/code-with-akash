class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int x,y;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                x=mp[nums[i]];
                y=i;
                break;
            }
            mp[target-nums[i]]=i;
        }
        return {x,y};
    }
};