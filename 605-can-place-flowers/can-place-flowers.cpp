class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n = flowerbed.size();

        if(k==0) return true;
        if(k > (n+1)/2) return false;
        if(n == 1){
            if(flowerbed[0]==1){
                return false;  
            }
            else if(flowerbed[0]==0){
                return true;
            }
        }

        
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            k--;
        }
        for (int i = 1; i < n - 1; i++) {
            if (flowerbed[i - 1] ==0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                k--;
                if (k == 0) {
                    break;
                }
            }
        }
        if (flowerbed[n - 2] == 0 && flowerbed[n - 1] == 0) {
            flowerbed[n-1]=1;
            k--;
        }

        if (k <= 0) {
            return true;
        } else {
            return false;
        }
    }
};