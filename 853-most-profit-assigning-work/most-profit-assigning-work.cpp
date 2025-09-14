class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({difficulty[i],profit[i]});
        }
        sort(begin(arr),end(arr));
        for(int i=1;i<arr.size();i++){
            arr[i].second = max(arr[i].second,arr[i-1].second);
        }

        // for(auto x:arr){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }


        int totalprofit=0;
        for(int i=0;i<m;i++){
            int s=0;
            int e=n-1;
            int profit=0;
            while(s<=e){
                int mid = s + (e-s)/2;
                if(arr[mid].first <= worker[i]){
                    profit = arr[mid].second;
                    s = mid+1;
                }
                else {
                    e = mid-1;
                }
            }
            totalprofit += profit;
        }
        return totalprofit;
    }
};