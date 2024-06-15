class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int,int>> vec;

        for(int i=0;i<n;i++){
            vec.push_back({capital[i],profits[i]});
        }

        sort(begin(vec),end(vec));

        priority_queue<int>pq;

        int i=0;
        while(k--){

            while(i<n && vec[i].first<= w){
                pq.push(vec[i].second);
                i++;
            }

            if(pq.empty()){
                break;
            }

            w += pq.top();
            pq.pop();
        }
        return w;
    }
};