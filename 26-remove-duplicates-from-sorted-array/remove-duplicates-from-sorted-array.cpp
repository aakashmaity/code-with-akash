class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        
        int i=0,j=0;
        while(j<n){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};