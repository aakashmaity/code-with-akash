class Solution {
public:
    #define ll long long
    bool judgeSquareSum(int c) {
        if(c==0 || c==1){
            return true;
        }
        ll s=0;
        ll e=sqrt(c);
        while(s<=e){
            ll a = s*s;
            ll b = e*e;
            if(a+b == c){
                return true;
            }
            else if(a+b > c){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
    }
};