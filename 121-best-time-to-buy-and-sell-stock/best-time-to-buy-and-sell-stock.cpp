class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxProfit(n,0);
        maxProfit[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxProfit[i] = max(maxProfit[i+1], prices[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,maxProfit[i]-prices[i]);
        }
        return ans;
    }
};