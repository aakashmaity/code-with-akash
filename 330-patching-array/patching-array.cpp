class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int size = nums.size();
        int patch=0;
        long maxReach=0;

        int i=0;
        while(maxReach < n){
            if( i<nums.size() && nums[i] <= maxReach + 1){
                maxReach += nums[i];
                i++;
            }
            else{
                int insert = maxReach+1; 
                maxReach += insert; 
                patch++;
            }
        }
        return patch;
    }
};