class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int row = 0;
        int col = m-1;

        int total=0;
        while(row<n && col>=0){
            if(grid[row][col] < 0){
                total += n-row;
                col--;
            }
            else{
                row++;
            }
        }
        return total;
    }
};