class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int ans=0;
        int l=0,h=0;
        while(h < n){
            if(nums[h]==0 && nums[l] == 1){
                ans = max(ans, h-l);
                l = h;
            }
            else if(nums[h] == 0 && nums[l]==0){
                l++;
                h++;
            }
            else{
                h++;
            }
        }
        ans = max(ans,h-l);
        return ans;
    }
};