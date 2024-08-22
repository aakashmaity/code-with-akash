class Solution {
public:
    int findComplement(int num) {

        int i=0;
        int ans=0;
        while(num){
            int bit = num&1; // extract bit
            int flip = bit^1;  // change it XOR 0^1 = 1 || 1^1 = 0
            ans += flip*pow(2,i++);  // change to decimal
            num=num>>1;
        }
        return ans;


    }
};