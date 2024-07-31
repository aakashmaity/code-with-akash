class Solution {
public:
    int n;
    int Width;
    int t[1001][1001];
    int solve(vector<vector<int>>& books, int i, int remWidth, int maxHt) {
        if (i >= n) {
            return maxHt;
        }

        if(t[i][remWidth] != -1){
            return t[i][remWidth];
        }

        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        // keep - place into the same shelf(if possible)
        if (bookW <= remWidth) {
            keep = solve(books, i + 1, remWidth - bookW, max(bookH, maxHt));
        }

        // skip - place into the next shelf
        skip = maxHt + solve(books, i+1, Width - bookW, bookH);

        t[i][remWidth] = min(skip,keep);
        
        return min(skip,keep);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(t, -1, sizeof(t));
        n = books.size();
        Width = shelfWidth;

        int remWidth = shelfWidth;

        return solve(books, 0, remWidth, 0);
    }
};