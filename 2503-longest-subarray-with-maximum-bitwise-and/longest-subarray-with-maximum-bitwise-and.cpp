class Solution {
public:
    // the bitwise AND of two different numbers will always be strictly less than the maximum of those two numbers.
    // Real question is find largest element then return max subarray which consists only of that element
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int len = 1;

        int mx = *max_element(nums.begin(),nums.end());

        int tempLen = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == mx){
                tempLen++;
            }
            else{
                len = max(len,tempLen);
                tempLen = 0;
            }
        }

        len = max(len,tempLen);
        return len;
    }
};