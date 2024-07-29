class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        int ans=0;
        for(int j=1;j<n-1;j++){
            // for increasing count
            int leftsmaller = 0;
            int rightgreater = 0;
            
            // for decreasing count
            int leftgreater = 0;
            int rightsmaller = 0;


            // finding for left side
            for(int i=j-1;i>=0;i--){
                if(rating[i] < rating[j]){
                    leftsmaller++;
                }
                else if(rating[i] > rating[j]){
                    leftgreater++;
                }
            }


            // finding for right side
            for(int k=j+1;k<n;k++){
                if(rating[j] < rating[k]){
                    rightgreater++;
                }
                else if(rating[j] > rating[k]){
                    rightsmaller++;
                }
            }

            ans += (leftsmaller * rightgreater) + (leftgreater * rightsmaller);
        }
        return ans;
    }
};