class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long rev=0;
        int n=x;
        while(n){
            int dig=n%10;
            rev=rev*10 + dig;
            n=n/10;
        }
        if(x==rev)
            return true;
        return false;
    }
};