class Solution {
public:
    int passThePillow(int n, int time) {
        int halfcycle = n - 1; // n-1 sec needed to pass the ball other side

        int totalHalfcycle = time / halfcycle;
        int rem = time % halfcycle;
        if (totalHalfcycle % 2 != 0) {
            return (n - rem);
        } else {
            return rem + 1;
        }
    }
};