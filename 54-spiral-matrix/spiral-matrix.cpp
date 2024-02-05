class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int strow=0;
        int stcol=0;
        int endrow=rows-1;
        int endcol=cols-1;

        int cnt=1;
        int total=rows*cols;
        vector<int> ans;

        while(cnt<=total)
        {
            //starting row
            for(int i=stcol;i<=endcol && cnt<=total;i++)
            {
                ans.push_back(matrix[strow][i]);
                cnt++;
            }
            strow++;

            //ending col
            for(int i=strow;i<=endrow && cnt<=total;i++)
            {
                ans.push_back(matrix[i][endcol]);
                cnt++;
            }
            endcol--;

            //ending row
            for(int i=endcol;i>=stcol && cnt<=total;i--)
            {
                ans.push_back(matrix[endrow][i]);
                cnt++;
            }
            endrow--;

            //starting col
            for(int i=endrow;i>=strow && cnt<=total;i--)
            {
                ans.push_back(matrix[i][stcol]);
                cnt++;
            }
            stcol++;
        }
        return ans;
    }
};