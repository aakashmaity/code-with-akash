class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>decode;

        for(int i=0;i<n;i++){
            int num = nums[i];
            int val=0;

            if(num == 0){
                val = mapping[0];
            }
            int curr_mul=1;
            while(num > 0){
                val += mapping[num%10]* curr_mul;
                curr_mul *= 10;
                num/=10;
            }
            decode[nums[i]] = val;
        }
        
        auto lambda = [&](int &a, int &b){
            if(decode[a] == decode[b]){
                return false;
            }
            return decode[a] < decode[b];
        };

        sort(begin(nums),end(nums),lambda);

        return nums;
    }
};