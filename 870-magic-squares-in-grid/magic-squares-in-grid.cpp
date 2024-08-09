class Solution {
public:
    bool isMagicSquare(vector<vector<int>> &grid, int row,int col){
        unordered_set<int>st;

        vector<int> rowSum(3,0);
        int k=0;
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        cout<<row<<" " <<col<<" "<<sum<<endl;
    
        for(int i=row;i<=row+2;i++){
            int currColsum = 0;
            for(int j=col;j<=col+2;j++){
                
                // check element is in b/w 0-9 
                if(grid[i][j] <= 0 || grid[i][j] > 9){
                    return false;
                }

                // check unique or not
                if(st.count(grid[i][j])){
                    return false;
                }
                st.insert(grid[i][j]);
                
                currColsum += grid[i][j];     // cols sums

                rowSum[k++] += grid[i][j];    // rows sums
                k = k%3;
            }
            // check col sums
            if(currColsum != sum){
                return false;
            }
        }
        // check row sums
        if(rowSum[0] != rowSum[1] || rowSum[1] != rowSum[2] || rowSum[0] != sum){
            return false;
        }

        // check digonals
        int leftdigo = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int rightdigo = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        if( leftdigo != rightdigo || leftdigo != sum){
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