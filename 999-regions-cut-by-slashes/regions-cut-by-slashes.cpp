class Solution {
public:
    // https://www.youtube.com/watch?v=zMqgIbLLsc4&t=1740s

    void numberOfIslandDFS(vector<vector<int>>& matrix, int i, int j){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix.size() || matrix[i][j] == 1){
            return;
        }

        matrix[i][j] = 1;   // mark as visited

        numberOfIslandDFS(matrix,i+1,j); // Down
        numberOfIslandDFS(matrix,i,j-1); // Left
        numberOfIslandDFS(matrix,i-1,j); // Up
        numberOfIslandDFS(matrix,i,j+1); // Right
    }


    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        
        vector<vector<int>> matrix(n*3, vector<int>(n*3,0));

        int regions = 0;
        
        // populate the matrix using the mapping of '/' and '\\'
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '/'){
                    matrix[i*3][j*3 + 2] = 1;
                    matrix[i*3 + 1][j*3 + 1] = 1;
                    matrix[i*3 + 2][j*3] = 1;
                }
                else if (grid[i][j] == '\\'){
                    matrix[i*3][j*3] = 1;
                    matrix[i*3 + 1][j*3 + 1] = 1;
                    matrix[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }

        //apply the concept of "Number of Island" question (DFS)
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                if(matrix[i][j] == 0){
                    numberOfIslandDFS(matrix,i,j);
                    regions++;
                }
            }
        }

        return regions;

    }
};