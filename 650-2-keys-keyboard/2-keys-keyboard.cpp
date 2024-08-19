class Solution {
public:
    int N;
    int solve(int currA, int clickBoard){
        if(currA == N){
            return 0;
        }
        if(currA > N){
            return 100000;
        }

        // copyAll and paste
        int copyPaste = 1 + 1 + solve(currA + currA , currA);
    
        // paste
        int paste = 1 + solve(currA + clickBoard, clickBoard);

        return min(copyPaste,paste);
    }
    
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        N=n;
        int currA = 1;
        int clickBoard = 1;
        
        return 1 + solve(currA,clickBoard);;
    }
};