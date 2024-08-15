class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            if(bills[i] == 5){
                mp[5]++;
            }
            else if(bills[i] == 10){
                if(mp.find(5) != mp.end() && mp[5] > 0){
                    mp[5]--;
                    mp[10]++;
                }
                else{
                    return false;
                }
            }
            else if(bills[i] == 15){
                if(mp.find(10) != mp.end() && mp[10] > 0){
                    mp[10]--;
                    mp[15]++;
                }
                else{
                    return false;
                }
            }
            else{
                if(mp.find(15) != mp.end() && mp[15] > 0){
                    mp[15]--;
                    mp[20]++;
                }
                else if(mp.find(10) != mp.end() && mp[10] > 0 && mp.find(5) != mp.end() && mp[5] > 0){
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp.find(5) != mp.end() && mp[5] >= 3){
                    mp[5] -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};