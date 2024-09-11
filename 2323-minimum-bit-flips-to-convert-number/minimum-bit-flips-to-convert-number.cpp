class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        while(start || goal){
            int bits = start & 1;
            int bitg = goal & 1;
            if(bits != bitg){
                cnt++;
            }
            start = start >> 1;
            goal = goal >> 1;
        }
        return cnt;
    }
};