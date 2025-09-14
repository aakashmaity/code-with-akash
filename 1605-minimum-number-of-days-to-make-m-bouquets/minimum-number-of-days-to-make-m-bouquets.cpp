class Solution {
public:
    int canMakeMBouquets(vector<int>& bloomDay, int day, int k){
        int bouquet =0;
        int count =0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }
            else{
                count=0;
            }

            if(count == k){
                bouquet++;
                count=0;
            }
        }
        return bouquet;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int ans =-1;
        int start_day = 0;
        int end_day = *max_element(begin(bloomDay),end(bloomDay));

        while(start_day <= end_day){
            int mid = start_day + (end_day - start_day)/2;
            if(canMakeMBouquets(bloomDay,mid,k) >= m){
                ans = mid;
                end_day = mid-1;
            }
            else{
                start_day = mid+1;
            }
        }
        return ans;
    }
};