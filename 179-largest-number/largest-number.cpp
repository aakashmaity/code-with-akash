class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int a: nums){
            string s = to_string(a);
            arr.push_back(s);
        }

        auto lambda = [&](string a, string b){
            if(a+b > b+a){
                return true;
            }
            return false;
        };

        sort(begin(arr),end(arr), lambda);

        if(arr[0] == "0"){
            return "0";
        }

        string ans = "";
        for(auto a: arr){
            ans += a;
        }

        return ans;
    }
};