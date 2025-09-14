class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>parityCounter(1,0);

        int k=0;
        for(int i=1;i<n;i++){
            if(nums[i]%2 == nums[i-1]%2)
                k++;
            parityCounter.push_back(k);
        }

        vector<bool>ans;
        for(vector<int>q : queries){
            ans.push_back(parityCounter[q[0]] == parityCounter[q[1]]);
        }

        return ans;
    }
};