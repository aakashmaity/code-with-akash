class Solution {
public:
    bool checkIfPossible(vector<int>& position,int force, int m){
        int prev = position[0];
        int countBalls = 1;

        for(int i=1;i<position.size();i++){
            if(position[i]-prev >= force){
                prev = position[i];
                countBalls++;
            }
            if(countBalls == m){
                break;
            }
        }
        return countBalls == m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(begin(position),end(position));

        int minForce=1;
        int maxForce=position[n-1]-position[0];

        int result=0;
        while(minForce <= maxForce){
            int mid = (minForce + maxForce)/2;
            if(checkIfPossible(position,mid,m)){
                result = mid;
                minForce = mid + 1;
            }
            else{
                maxForce = mid - 1;
            }
        }
        return result;
    }
};