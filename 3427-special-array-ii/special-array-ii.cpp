class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int>converted(1,0);
        vector<bool>ans;
        int k=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]%2 == nums[i-1]%2)
                k++;
            converted.push_back(k);
        }
        for(int i=0;i<m;i++)
        {
            ans.push_back(converted[queries[i][0]] == converted[queries[i][1]]);
        }
        return ans;
    }
};