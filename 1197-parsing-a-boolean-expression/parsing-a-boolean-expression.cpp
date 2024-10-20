class Solution {
public:
    char solveOp(vector<char> &values, char op){
        if(op =='!'){
            return values[0] == 't' ? 'f' : 't';
        }
        else if(op == '&'){
            for(char &ch: values){
                if(ch == 'f'){
                    return 'f';
                }
            }
            return 't';
        }
        else if(op == '|'){
            for(char &ch: values){
                if(ch == 't'){
                    return 't';
                }
            }
            return 'f';
        }

        return 't'; //never come here
    }
    bool parseBoolExpr(string exp) {
        int n = exp.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if(exp[i] == ','){
                continue;
            }

            if (exp[i] == ')') {
                vector<char> values;
                while (!st.empty() && st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                
                st.pop();
                char op = st.top();
                st.pop();
                
                char temp = solveOp(values,op);

                st.push(temp);
            }
            else{
                st.push(exp[i]);
            }
        }
        return st.top() == 't'? true : false;
    }
};