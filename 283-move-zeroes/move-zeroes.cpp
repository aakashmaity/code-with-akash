class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        int i=0,j=1;
        if(nums.size()==1)
            return;
        while(j<n && i<j)
        {
            if(nums[i]!=0)
                i++;
            if(nums[j]==0)
                j++;
            if(j<n && nums[i]==0 && nums[j]!=0)
                swap(nums[i++],nums[j]);
            j++;
            
        }
    }
};