class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> track(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            int mini = INT_MAX;
            int col = 0;
            for(int j=0;j<n;j++){
                if(mini > matrix[i][j]){
                    mini = matrix[i][j];
                    col = j;
                }
            }
            track[i][col]=1;
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            int maxi = INT_MIN;
            int row = 0;
            for(int j=0;j<m;j++){
                if(maxi < matrix[j][i]){
                    maxi = matrix[j][i];
                    row = j;
                }
            }
            if(track[row][i] == 1){
                ans.push_back(matrix[row][i]);
            }
        }

        return ans;
    }
};