class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int currUnsat=0,maxUnsat=0;

        // creating first window of size "minutes"
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1)
                currUnsat += customers[i];
        }

        maxUnsat = currUnsat;

        int i=0;
        int j=minutes;
        while (j < n) {
            // adding element in a window
            if(grumpy[j]==1){
                currUnsat += customers[j];
            }
            // removing element from window
            if(grumpy[i]==1){
                currUnsat -= customers[i];
            }

            maxUnsat = max(maxUnsat,currUnsat);

            i++;
            j++;
        }
        
        int totalSat = maxUnsat;  // using power 
        // now adding all must have satisfied customers
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                totalSat += customers[i];
            }
        }
        return totalSat;
    }
};