class Solution {
public:
    int findSetbits(int n){
        int cnt=0;
        while(n){
            if(n&1 == 1){
                cnt++;
            }
            n = n>>1;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int &n: nums){
            mp[n] = findSetbits(n);
        }
        
        for(int i=1;i<n;i++){

            int j=i;
            if(nums[i-1] > nums[i]){
                while(j>0 && nums[j-1] > nums[j]){
                    int s1 = mp[nums[j]];
                    int s2 = mp[nums[j-1]];
                    if(s1 != s2){
                        return false;
                    }
                    swap(nums[j],nums[j-1]);
                    j--;
                }
            }
        }
        for(int n: nums){
            cout<<n<<" ";
        }
        
        
        return true;
    }
};