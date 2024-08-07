class Solution {
public:
    typedef pair<int,int> P;  // subArray sum, end index of this subArray
    int MOD = 1e9+7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // M
        priority_queue< P, vector<P> , greater<P> > pq;  // Min Heap
        
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        int ans = 0;

        for(int count = 1;count<=right;count++){
            auto p = pq.top();
            pq.pop();

            int sum = p.first;
            int idx = p.second;

            if(count >= left){
                ans = (ans + sum) % MOD;
            }

            P new_pair;

            int new_idx = idx+1;
            if(new_idx < n){
                new_pair.first = sum+nums[new_idx];
                new_pair.second = new_idx;
                pq.push(new_pair);
            }
        }
        return ans;
    }
};