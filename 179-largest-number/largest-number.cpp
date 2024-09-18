class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto lambda = [&](int& a, int& b){
            string num1 = to_string(a);
            string num2 = to_string(b);
            if(num1+num2 > num2+num1){
                return true;
            }
            return false;
        };

        sort(begin(nums),end(nums), lambda);
        
        if(nums[0] == 0){
            return "0";
        }

        string ans = "";
        for(auto a: nums){
            ans += to_string(a);
        }

        return ans;
    }
};