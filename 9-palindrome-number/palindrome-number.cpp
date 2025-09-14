class Solution {
public:
    bool isPalindrome(int x) {
        long n = x;
        long rev=0;
        while(n){
            rev = rev*10 + n%10;
            n=n/10;
        }
        if(abs(x)==rev)
            return true;
        return false;
    }
};