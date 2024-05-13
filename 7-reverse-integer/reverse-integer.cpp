class Solution {
public:
    int reverse(int n ) {
        long ans=0;
        while(n){
            ans = ans*10 + n%10; 
            n=n/10;
        }
        if(ans>INT_MAX || ans<INT_MIN)
            return 0;
        return int(ans);
    }
};