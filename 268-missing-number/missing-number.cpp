class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> present(n+1,0);
        for(int i=0;i<n;i++){
            present[nums[i]] = 1;
        }
        for(int i=0;i<n+1;i++){
            if(present[i]==0)
                return i;
        }
        return -1;
    }
};