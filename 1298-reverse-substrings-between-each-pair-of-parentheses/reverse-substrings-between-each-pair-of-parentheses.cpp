class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i] == ')'){
                string str;
                
                // adding characters
                while(st.top() != '('){
                    str+=st.top();
                    st.pop();
                }
                st.pop();

                // push into the stack in the reverse order
                for(int j=0;j<str.size();j++){
                    st.push(str[j]);
                }
            }
            else{
                st.push(s[i]);
            }
        }

        string ans;
        while(!st.empty()){
            ans=st.top() + ans;
            st.pop();
        }
        return ans;
    }
};