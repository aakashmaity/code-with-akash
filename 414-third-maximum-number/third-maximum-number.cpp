class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n=nums.size();
        int cnt=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] != nums[i+1]){
                cnt++;
            }
            if(cnt==3){
                return nums[i];
            }
        }
        return nums[n-1];
    }
};