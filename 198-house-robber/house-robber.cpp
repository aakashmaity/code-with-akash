class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> v (n+1,0);
        v[1]=nums[0];
        for(int i=2;i<=n;i++)
        {
            int steal = nums[i-1]+ v[i-2];
            int skip = v[i-1];
            v[i] = max(steal,skip);
        }
        return v[n];
    }
};