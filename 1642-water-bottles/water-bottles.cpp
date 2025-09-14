class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles > 0) {
            ans += numBottles / numExchange;
            int rem = numBottles % numExchange;
            numBottles /= numExchange;
            numBottles += rem;
            if(numBottles < numExchange){
                break;
            }
            cout << numBottles << " " << rem << endl;
        }
        return ans;
    }
};