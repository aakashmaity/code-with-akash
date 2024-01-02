class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Moore Voting Algorithm

        int n = nums.size();
        int count=0;
        int major=0;
        int i=0;
        while(i<n)
        {
            if(count==0){
                major=nums[i];
            }

            if(nums[i]!= major){
                count--;
            }
            else{
                count++;
            }
            i++;
        }
        return major;
    }
};