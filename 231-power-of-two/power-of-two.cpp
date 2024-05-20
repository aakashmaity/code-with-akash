class Solution {
public:
    bool solve(int n){
        for(int i=0;i<=sqrt(n)+1;i++){
            if(pow(2,i)==n)
                return true;
        }
        return false;
    }
    bool isPowerOfTwo(int n) {
        return solve(n);
    }
};