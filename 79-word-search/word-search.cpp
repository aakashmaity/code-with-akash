class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, vector<vector<int>> &vis,int i,int j,int m,int n, int k)
    {
        if (k >= word.size())
            return true;
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        if(vis[i][j]==1)
            return false;
        if(word[k] != board[i][j])
            return false;
        
        
        vis[i][j]=1;
        int x[4] = {0,-1,0,1};
        int y[4] = {-1,0,1,0};
        bool temp = false;
        for(int index=0;index<4;index++)
        {
            if(helper(board,word,vis,i+x[index],j+y[index],m,n,k+1))
                temp = temp || true;
        }
        vis[i][j]=0;
        return temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if(n==0)
            return false;
        int m = board[0].size();
        if(m==0)
            return false;
        vector<vector<int>> vis( n , vector<int> (m,0)); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(word[0]==board[i][j])
                    if(helper(board,word,vis,i,j,m,n,0))
                        return true;
            }
        }
        return false;

    }
};