class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes; 
        int ans = INT_MAX;

        for(auto a: timePoints){
            string hour = a.substr(0,2);
            string min = a.substr(3,2);

            int hh = stoi(hour);
            int mm = stoi(min);

            if(hh == 0){
                hh = 24;
            }
            
            minutes.push_back(60*hh + mm);
        }
        sort(begin(minutes),end(minutes));
        for(int i=1;i<minutes.size();i++){
            ans = min(ans, minutes[i] - minutes[i-1]);
        }

        ans = min(ans, 24 * 60 - minutes.back() + minutes.front());

        return ans;
    }
};