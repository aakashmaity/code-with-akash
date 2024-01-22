class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+1,0);
        for(auto i: nums)
        {
            freq[i]++;
        }
        int dup,mis,end=2;
        for(int i=1;i<=n;i++)
        {
            if(freq[i]==2)
            {
                dup=i;
                end--;
            }
                
            if(freq[i]==0)
            {
                mis=i;
                end--;
            }
            
            if(!end)
                break;
        }

        return {dup,mis};
    }
};