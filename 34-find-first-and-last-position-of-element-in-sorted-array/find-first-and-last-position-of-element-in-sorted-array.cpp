class Solution {
public:
    #define ll long long
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int start=-1,end=-1;

        int s = 0;
        int e = n-1;

        while(s<=e){
            ll mid = s +(e-s)/2;
            if(nums[mid]==target){
                start=mid;
                e=mid-1;
            }
            else if(nums[mid] < target) {
                s = mid+1;
            }
            else{
                e=mid-1;
            }
        }
        s=0;
        e=n-1;
        while(s<=e){
            ll mid = s +(e-s)/2;
            if(nums[mid]==target){
                end=mid;
                s=mid+1;
            }
            else if(nums[mid] < target) {
                s = mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return {start,end};
    }
};