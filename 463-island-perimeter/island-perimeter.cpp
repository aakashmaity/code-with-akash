class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dirx[4] = {-1,0,1,0};
        int diry[4] = {0,1,0,-1};

        int perim=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int cntZeros=0;
                    for(int k=0;k<4;k++){
                        int newx = i+dirx[k];
                        int newy = j+diry[k];
                        if(newx < 0 || newx > n-1 || newy < 0 || newy > m-1){
                            cntZeros++;
                        }
                        else if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 0){
                            cntZeros++;
                        }
                    }
                    perim += cntZeros;
                    cout<<i<<j<<" "<<cntZeros<<endl;
                }
            }
        }
        return perim;
    }
};