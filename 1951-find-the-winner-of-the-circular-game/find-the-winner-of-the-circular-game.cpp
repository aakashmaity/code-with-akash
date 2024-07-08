class Solution {
public:
    // void print_queue(queue<int> q) {
    //     queue<int> temp = q;
    //     while (!temp.empty()) {
    //         cout << temp.front() << " ";
    //         temp.pop();
    //     }
    //     cout<<endl;
    // }
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        while (q.size() > 1) {
            for (int i = 1; i <= k - 1; i++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};