class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        string temp;
        vector<string>ans;

        if(n==0){
            return {};
        }
        int s=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]+1 != nums[i]){
                if(nums[s]!=nums[i-1]){
                    temp = to_string(nums[s]);
                    temp += "->";
                    temp += to_string(nums[i-1]);
                }
                else{
                    temp = to_string(nums[s]);
                }
                ans.push_back(temp);
                s=i;
                temp="";
            }
        }

        // to handle last one
        if(nums[s]!=nums[n-1]){
            temp = to_string(nums[s]);
            temp += "->";
            temp += to_string(nums[n-1]);
        }
        else{
            temp = to_string(nums[s]);
        }
        ans.push_back(temp);
    
        return ans;
    }
};