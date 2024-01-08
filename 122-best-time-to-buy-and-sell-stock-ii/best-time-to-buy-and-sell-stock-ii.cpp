class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> maxProfit(n,0);
        maxProfit[n-1]=prices[n-1];
        int ans=0;
        for(int i=n-2;i>=0;i--)
        {
            maxProfit[i] = max(maxProfit[i+1],prices[i]);
            ans += (maxProfit[i]-prices[i]);
            maxProfit[i]=prices[i];
        }
        return ans;
    }
};