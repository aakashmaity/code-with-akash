class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>maxProfits(n);

        int maxi = prices[n-1];
        for(int i=n-1;i>=0;i--){
            maxi = max(prices[i],maxi);
            maxProfits[i] = maxi;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(maxProfits[i] - prices[i], ans );
        }

        return ans;
    }
};