class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i] == ']' && st.top() == '['){
                st.pop();
            }
            else if(s[i] == '['){
                st.push('[');
            }
        }

        int size = st.size();

        int swaps = (size + 1)/2;
        return swaps;
    }
};