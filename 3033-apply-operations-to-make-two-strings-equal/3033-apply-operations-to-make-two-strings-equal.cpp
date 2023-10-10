class Solution {
public:
    int solve(int i,int j,vector<int> &diffarr,int &x,vector<vector<int>> &dp)
    {
        if(i>=j)
            return 0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int left2=min(x,diffarr[i+1]-diffarr[i])+solve(i+2,j,diffarr,x,dp);
        int right2=min(x,diffarr[j]-diffarr[j-1])+solve(i,j-2,diffarr,x,dp);
        int leftright=min(x,diffarr[j]-diffarr[i])+solve(i+1,j-1,diffarr,x,dp);
        dp[i][j]=min(left2,min(right2,leftright));
        return dp[i][j];
    }
    int minOperations(string s1, string s2, int x) {
        int n=s1.size();
        vector<vector<int>> dp(n+1 , vector<int> (n+1,-1));
        vector<int> diffarr;
        //store diff indexes in a diffarr
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                diffarr.push_back(i);
            }
        }
        //odd number of differences present
        if(diffarr.size()%2!=0)
            return -1;
        return solve(0,diffarr.size()-1,diffarr,x,dp);
    }
};