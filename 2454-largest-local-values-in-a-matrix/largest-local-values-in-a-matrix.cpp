class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2,vector<int>(n-2,-1));
        for(int i=0;i<=n-3;i++)
        {
            for(int j=0;j<=n-3;j++)
            {
                int maxval=-1;
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        int val = grid[i+x][j+y];
                        maxval=max(maxval,val);
                    }
                }
                maxLocal[i][j]=maxval;
            }
        }
        return maxLocal;
    }
};