class Solution {
public:
    string solve(string num1, string num2){
        int s1=num1.size();
        int s2=num2.size();
        string ans;
        int i=s1-1,j=s2-1;
        int carry =0;
        while(i>=0 && j>=0)
        {
            int x = num1[i]-'0';
            int y = num2[j]-'0';
            int sum = carry + x + y;
            int rem = sum%10;
            carry=sum/10;
            ans+=to_string(rem);
            i--;
            j--;
        }
        while(i>=0){
            int sum = carry + (num1[i]-'0');
            int rem = sum%10;
            carry=sum/10;
            ans+=to_string(rem);
            i--;
        }
        if(carry){
            ans+=to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string addStrings(string num1, string num2) {
        if(num1.size()>=num2.size())
            return solve(num1,num2);
        else
            return solve(num2,num1);
        
    }
};