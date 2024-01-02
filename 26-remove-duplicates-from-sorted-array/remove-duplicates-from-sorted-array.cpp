class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int i=0,j=0;
        while(j<n)
        {
            if(nums[j]!=nums[i])
            {
                nums[++i]=nums[j++];
            }
            else
                j++;
        }
        return i+1;
    }
};