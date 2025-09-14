class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=26;

        vector<vector<long long>> dist(n,vector<long long>(n,INT_MAX));

        // making a-a,b-b,c-c,.... = 0
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        // adding initial costs to goes from src to dest
        for(int i=0;i<original.size();i++){
            int src = original[i] - 'a';
            int dest = changed[i] - 'a';
            long long wt = cost[i];

            dist[src][dest] = min(dist[src][dest] , wt);
        }

        //floyd warshal algo
        for(int k=0;k<n;k++){   //k indecates no. of intermediates path
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = min(dist[i][j] , dist[i][k]+dist[k][j]);
                }
            }
        }

        // calculate answer
        long long ans=0;
        for(int i=0;i<source.size();i++){
            int src = source[i] - 'a';
            int dest = target[i] - 'a';

            if(dist[src][dest] == INT_MAX){
                return -1;
            }

            ans += dist[src][dest];

        }
        return ans;

    }
};