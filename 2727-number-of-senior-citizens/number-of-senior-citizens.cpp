class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;

        for(string pass: details){
            string age = pass.substr(11,2);
         
            if(stoi(age) > 60){
                ans++;
            }
        }
        return ans;
    }
};