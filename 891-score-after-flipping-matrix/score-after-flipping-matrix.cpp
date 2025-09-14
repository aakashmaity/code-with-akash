class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // to flip rows
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    grid[i][j] = 1-grid[i][j];
                }
            }
        }

        // to flip columns
        for(int i=1;i<m;i++)
        {
           //counting no of 0's
           int countZero=0;
           for(int j=0;j<n;j++)
           {
                if(grid[j][i]==0)
                    countZero++;
           }

           if(countZero > n-countZero){
                
                for(int j=0;j<n;j++){
                    grid[j][i]=1-grid[j][i];
                }
           }
        }


        ///calculating answer
        int ans=0;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<m;j++){
                temp+= grid[i][j] * pow(2,m-j-1);
            }
            ans+=temp;
        }
        return ans;
    }
};