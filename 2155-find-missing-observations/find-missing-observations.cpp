class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();

        int sum=0;
        for(int e : rolls){
            sum+=e;
        }

        int totalSum = mean * (m+n);
        int missingSum = totalSum - sum;

        
        if(missingSum > 6*n || missingSum < n){
            return {};
        }

        vector<int>ans;
        while(missingSum && n>=1){
            int neww = min(6,missingSum - n + 1);
            ans.push_back(neww);
            
            missingSum -= neww;
            n--; 
        }
        return ans;
        
    }
};