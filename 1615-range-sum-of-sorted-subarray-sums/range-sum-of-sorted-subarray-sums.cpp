class Solution {
public:
    int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int>subarrSum;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                subarrSum.push_back(sum);
            }
        }
        sort(begin(subarrSum),end(subarrSum));
        int ans=0;
        for(int i=left-1;i<right;i++){
            ans = (ans + subarrSum[i]) % MOD;
        }
        return ans;
    }
};