class Solution {
public:
    int n,m;
    vector<int>ans;

    void solve(vector<vector<int>>& matrix, int top, int right, int bottom, int left){
        if(ans.size() >= n*m ){
            return;
        }
        
        // traverse right
        for(int i=left;i<=right && ans.size() < m*n;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        // traverse down
        for(int i=top;i<=bottom && ans.size() < m*n;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        // traverse left
        for(int i=right;i>=left && ans.size() < m*n;i--){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;

        // traverse up
        for(int i=bottom;i>=top && ans.size() < m*n;i--){
            ans.push_back(matrix[i][left]);
        }
        left++;

        solve(matrix,top,right,bottom,left);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        solve(matrix,0,m-1,n-1,0);
        return ans;     
    }
};