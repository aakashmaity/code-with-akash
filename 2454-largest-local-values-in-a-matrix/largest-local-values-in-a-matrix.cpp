class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2,vector<int>(n-2,-1));
        for(int i=0;i<=n-3;i++)
        {
            for(int j=0;j<=n-3;j++)
            {
                int x = max({grid[i][j],grid[i][j+1], grid[i][j+2]});
                int y = max({grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2]});
                int z = max({grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]});
                
                maxLocal[i][j]=max({x,y,z});
            }
        }
        return maxLocal;
    }
};