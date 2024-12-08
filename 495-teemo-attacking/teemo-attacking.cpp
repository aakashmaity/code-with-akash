class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        for(int i=0;i<timeSeries.size()-1;i++){
           int t = timeSeries[i];
           for(int j=t;j<t+duration;j++){
                if(j<timeSeries[i+1])
                    ans++;
                else
                    break;
           }
        }
        return ans+duration;
    }
};