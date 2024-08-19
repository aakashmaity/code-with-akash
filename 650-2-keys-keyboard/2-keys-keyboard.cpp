class Solution {
public:
    int N;
    int dp[1001][1001];
    int solve(int currA, int clickBoard){
        if(currA == N){
            return 0;
        }
        if(currA > N){
            return 100000;
        }

        if(dp[currA][clickBoard] != -1){
            return dp[currA][clickBoard];
        }

        // copyAll and paste
        int copyPaste = 1 + 1 + solve(currA + currA , currA);
    
        // paste
        int paste = 1 + solve(currA + clickBoard, clickBoard);

        dp[currA][clickBoard] = min(copyPaste,paste);

        return dp[currA][clickBoard];
    }
    
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        N=n;
        memset(dp,-1,sizeof(dp));
        int currA = 1;
        int clickBoard = 1;
        
        return 1 + solve(currA,clickBoard);;
    }
};