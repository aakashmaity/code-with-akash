class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        string ans;
        int carry=0;
        while(i>=0 || j>=0 || carry==1){
            if(i>=0){
                carry+=a[i--]-'0';
            }
            if(j>=0){
                carry+=b[j--]-'0';
            }
            
            ans+=carry%2 +'0';
            // cout<<carry<<" "<<ans<<endl;
            carry=carry/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};