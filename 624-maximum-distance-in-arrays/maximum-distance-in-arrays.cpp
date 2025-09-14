class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int mini,maxi;

        int m = arrays[0].size();
        mini = arrays[0][0];
        maxi = arrays[0][m-1];

        int maxDis = -1;

        for(int i=1;i<n;i++){
            m = arrays[i].size();
            int currDis1 = abs(arrays[i][0] - maxi);
            int currDis2 = abs(arrays[i][m-1] - mini);

            maxDis = max(maxDis, currDis1);
            maxDis = max(maxDis, currDis2);

            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i][m-1]);
        }

        return maxDis;
    }
};