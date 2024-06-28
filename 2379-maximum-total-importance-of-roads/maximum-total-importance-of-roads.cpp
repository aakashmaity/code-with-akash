class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int s = roads.size();
        vector<int> conn(n,0);
        for(int i=0;i<s;i++){
            conn[roads[i][0]]++;
            conn[roads[i][1]]++;
        }
        sort(begin(conn),end(conn));

        long ans=0;
        long cnt=1;
        for(int x: conn){
            ans += x * (cnt++);
        }
        return ans;
    }
};