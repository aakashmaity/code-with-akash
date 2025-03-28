class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>>ans(r,vector<int>(c));
        int n=mat.size();
        int m=mat[0].size();

        if(r*c != m*n){
            return mat;
        }

        int p=0,q=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(q >= m){
                    p++;
                    q = 0;
                }
                cout<<p<<" "<<q<<endl;
                int data = mat[p][q++];
                ans[i][j] = data;
            }
        }
        return ans;
    }
};