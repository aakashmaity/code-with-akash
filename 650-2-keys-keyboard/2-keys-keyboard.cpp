class Solution {
public:
    int N;
    int ans = INT_MAX;
    void solve(int currA, int clickBoard, int res){
        if(currA == N){
            ans = min(ans,res);
        }
        if(currA > N){
            return;
        }

        // copyAll and paste
        solve(currA + currA , currA, res+2);
    
        // paste
        solve(currA + clickBoard, clickBoard, res+1);

    }
    
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        N=n;
        int currA = 1;
        int clickBoard = 1;
        solve(currA,clickBoard,1);
        return ans;
    }
};