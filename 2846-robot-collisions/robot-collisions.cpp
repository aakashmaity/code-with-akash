class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();  
        
        vector<int> actualIndex(n); 
        iota(begin(actualIndex),end(actualIndex),0);  // 0,1,2,....,n-1

        // sort the actualIndex in the order of robots placed 
        auto lambda = [&](int &i, int &j){
            return positions[i] < positions[j];
        };

        sort(begin(actualIndex),end(actualIndex),lambda);   // 2,0,1,3 - example 2

        stack<int> st;
        for(int &currIdx : actualIndex)
        {
            if(directions[currIdx] == 'R'){
                st.push(currIdx);
            }
            else{  // towards 'L'
                while(!st.empty() && healths[currIdx] > 0){
                    int topIdx = st.top();
                    st.pop();

                    if(healths[currIdx] < healths[topIdx]){
                        healths[currIdx] = 0;
                        healths[topIdx] -= 1;
                        st.push(topIdx);
                    }
                    else if(healths[currIdx] > healths[topIdx]){
                        healths[topIdx] = 0;
                        healths[currIdx] -= 1;
                    }
                    else{
                        healths[topIdx] = 0;
                        healths[currIdx] = 0;
                    }
                }
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(healths[i] > 0){
                res.push_back(healths[i]);
            }
        }
        
        return res;
    }
};