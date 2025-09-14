class Solution {
public:
    #define ll long long
    int mySqrt(int x) {
        int start=0;
        int end=x;

        int ans;
        while(start <= end){
            ll mid = start + (end-start)/2;
            if(mid*mid > x){
                end = mid-1;
            }
            else if (mid*mid<x){
                start = mid+1;
                ans=mid;
            }
            else{
                ans=mid;
                break;
            }
        }
        return ans;
    }
};