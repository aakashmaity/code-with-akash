class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.size();
        string str;
        for(int i=0;i<n;i++){
            str += to_string(s[i]-96);
        }

        while(k--){
            int ans=0;
            for(int i=0;i<str.size();i++){
                ans += str[i] - '0';
            }
            str = to_string(ans);
        }
        int res = stoi(str);
        return res;
    }
};