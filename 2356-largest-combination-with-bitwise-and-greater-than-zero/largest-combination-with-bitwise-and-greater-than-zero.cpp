class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int maxCom = 0;
        for(int i=0;i<32;i++){
            int count =0;
            for(int num: candidates){
                if((num >> i) & 1 != 0){
                    count++;
                }
            }
            maxCom = max(maxCom,count);
        }
        return maxCom;
    }
};