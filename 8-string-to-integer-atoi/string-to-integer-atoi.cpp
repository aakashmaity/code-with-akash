class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        double res=0;
        int i=0;
        while(s[i]==' '){
            i++;
        }
        bool positive = (s[i]=='+');
        bool negative = (s[i]=='-');
        if(positive || negative)
            i++;
           
        while(s[i]>='0' && s[i]<='9' && i<n){
            res = res*10 + (s[i]-'0');
            i++;
        }
        cout<<res<<endl;
        if(negative)
            res = -res;
        
        if(res > INT_MAX)
            res=INT_MAX;
        else if(res < INT_MIN)
            res=INT_MIN;

        return int(res);
    }
};