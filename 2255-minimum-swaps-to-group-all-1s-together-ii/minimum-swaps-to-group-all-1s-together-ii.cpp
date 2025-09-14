class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();

        if(n < 4){
            return 0;
        }
        int onecount = 0;
        for(int x: nums){
            if(x==1)
                onecount++;
        }
        int win = onecount;

        int zeros=0;
        int i=0;
        int j=0;
        while(j<win){
            if(nums[j] == 0){
                zeros++;
            }
            j++;
        }

        int minZeros = INT_MAX;
        minZeros = min(zeros,minZeros);
        
        while(i<n){
            if(nums[i]==0){
                zeros--;
            }
            i++;
            if(nums[j] == 0){
                zeros++;
            }
            
            minZeros = min(zeros,minZeros);
            
            j++;
            j = j%n;
        }

        return minZeros;
    }
};