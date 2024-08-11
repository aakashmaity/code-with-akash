class Solution {
public:
    int n,m;
    // possible ans can be 0,1,2 - you can make island into two part
    void DFS(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0 || visited[i][j] == 1){
            return;
        }

        visited[i][j] = 1;

        DFS(grid,visited,i+1,j);
        DFS(grid,visited,i,j-1);
        DFS(grid,visited,i-1,j);
        DFS(grid,visited,i,j+1);
    }
    int numberOfIsland(vector<vector<int>>& grid){
        int island = 0;

        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && visited[i][j] != 1){
                    DFS(grid,visited,i,j);
                    island++;
                }
            }
        }
        return island;
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int island = numberOfIsland(grid);
        if(island > 1 || island == 0){
            return 0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int islandCount = numberOfIsland(grid);

                    if(islandCount > 1 || islandCount == 0){
                        return 1;     // days - making only one change
                    }
                    grid[i][j] = 1;
                }
            }
        }
        

        return 2;  // day - making 2 changes (seperate corner element) 
    }
};