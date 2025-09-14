class Solution {
public:
    int solvecount(vector<int>& nums, int target)
    {
        int cnt=0;
        for(auto &ele : nums){
            if(ele >= target)
                cnt++;
        }
        return cnt;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=0;
        int e = nums.size();

        while(s<=e){
            int mid = s+(e-s)/2;
            int cnt = solvecount(nums,mid);
            
            if(cnt>mid){
                s = mid + 1;
            }   
            else if(cnt<mid){
                e = mid - 1;
            }
            else{
                return cnt;    // cnt == mid
            }
        }

        return -1;
    }
};