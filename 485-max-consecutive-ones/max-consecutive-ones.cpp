class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = 0;
        int ans=0;
        int count=0;
        for(auto n: nums){
            if(n == 1){
                count++;
                ans = max(ans,count);
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
};