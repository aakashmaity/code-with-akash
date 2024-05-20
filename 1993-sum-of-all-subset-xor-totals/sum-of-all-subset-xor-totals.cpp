class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int orsum = 0;
        for(int i=0;i<n;i++)
        {
            orsum |= nums[i];
        }

        return orsum << (n-1); //add n-1 0's after orsum
    }
};