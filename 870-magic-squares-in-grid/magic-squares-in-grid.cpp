class Solution {
public:
    bool isMagicSquare(vector<vector<int>> &grid, int row,int col){
        unordered_set<int>st;

        // check unique and check 1-9
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int num = grid[row+i][col+j];
                if(num <= 0 || num > 9 || st.count(num)){
                    return false;
                }
                st.insert(num);
            }
        }

        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        for(int i=0;i<3;i++){
            // check col
            if(grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2] != sum){
                return false;
            }

            // check row
            if(grid[row][col+i] + grid[row+1][col+i] + grid[row+2][col+i] != sum){
                return false;
            }
        }

        // check left digonal
        if(grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != sum){
            return false;
        }
        // check right digonal
        if(grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != sum){
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n<3 || m<3){
            return 0;
        }

        int count = 0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(isMagicSquare(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};