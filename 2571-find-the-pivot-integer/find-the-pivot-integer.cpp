class Solution {
public:
    int pivotInteger(int n) {
        int lsum=(n*(n+1))/2;
        int rsum=0;
        for(int i=n;i>=0;i--)
        {
            rsum+=i;
            if(lsum==rsum)
                return i;
            lsum-=i;
            
        }
        return -1;
    }
};