class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans(n);
        int k=n-1;
        int i=0;
        int j=n-1;
        
        while(i<=j){
            int lsq = nums[i]*nums[i];
            int rsq = nums[j]*nums[j];
            if(lsq > rsq){
                ans[k--] = lsq;
                i++;
            }
            else{
                ans[k--]=rsq;
                j--;
            }
        }
        return ans;
    }
};