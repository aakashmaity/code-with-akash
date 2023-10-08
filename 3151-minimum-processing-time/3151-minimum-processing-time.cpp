class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n=processorTime.size();
        int m=4*n;
        int ans=INT_MIN;
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.rbegin(),tasks.rend());
        int j=0;
        for(int i=0;i<m;i=i+4){
            int sum=processorTime[j++]+tasks[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};