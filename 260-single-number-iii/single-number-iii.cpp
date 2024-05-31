class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }

        vector<int> ans;
        for (auto& pair : freq) {
            if (pair.second == 1) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};