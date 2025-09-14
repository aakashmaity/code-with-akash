class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target =0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target){
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum<target)
                    j++;
                else
                    k--;
            }
        }
        vector<vector<int>>ans;
        for(auto x: st)
            ans.push_back(x);
        return ans;
    }
};