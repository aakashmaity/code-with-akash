class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        vector<int> ans(2);
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(mp.find(target - x) != mp.end()){
                ans[0] = mp[target-x];
                ans[1] = i;
                break;
            }
            mp[x] = i;
        }
        return ans;
    }
};