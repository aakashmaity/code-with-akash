class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MAX) {
            if (x == 1)
                return 1;
            else if (x == -1)
                return -1;
            else
                return 0;
        }
        if (n == INT_MIN) {
            if (x == 1 || x == -1) {
                return 1;
            } else {
                return 0;
            }
        }

        double ans = 1;
        if (n >= 0) {
            while (n--) {
                ans *= x;
            }
        } else {
            while (n < 0) {
                ans /= x;
                n++;
            }
        }
        return ans;
    }
};