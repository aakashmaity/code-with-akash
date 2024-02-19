class Solution {
public:
    vector<int> countBits(int n) {
        // if(n==0)
        //     return {0};
        vector<int>ans(n+1);
        // ans[0]=0;
        for(int j=0;j<=n;j++)
        {
            int rem = j%2;
            int quo = j/2;
            ans[j]=ans[quo]+rem;
        }
        return ans;
    }
};