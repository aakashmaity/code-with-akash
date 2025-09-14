class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int moves=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]){
                nums[i]++;
                moves++;
            }
            else if(nums[i-1]>nums[i]){
                int diff = nums[i-1]-nums[i]+1 ;
                nums[i]+=diff;
                moves+=diff;
            }
        }
        return moves;
    }
};