class Solution {
public:
    int n,m;
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m){
            return true;
        }

        if(grid2[i][j] != 1){   // we only need lands
            return true;
        }

        grid2[i][j] = -1;        // mark as visited

        bool result = (grid1[i][j] == 1);

        result = result & checkSubIsland(grid1, grid2, i+1, j);  //down
        result = result & checkSubIsland(grid1, grid2, i, j-1);  //left
        result = result & checkSubIsland(grid1, grid2, i-1, j);  //up
        result = result & checkSubIsland(grid1, grid2, i, j+1);  //right

        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();

        int subIslands=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)){
                    subIslands++;
                }
            }
        }
        return subIslands;
    }
};