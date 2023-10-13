class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left;
        vector<int> right;
        int maxh=INT_MIN;
        for(int i = 0;i<n;i++){
            maxh=max(maxh,height[i]);
            left.push_back(maxh);
        }
        maxh=INT_MIN;
        for(int i = n-1;i>=0;i--){
            maxh=max(maxh,height[i]);
            right.insert(right.begin(),maxh);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};