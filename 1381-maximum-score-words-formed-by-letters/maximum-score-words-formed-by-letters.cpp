class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        int res = 0;

        vector<int> letters_count(26, 0);
        for (char letter : letters) {
            letters_count[letter - 'a']++;
        }

        unordered_map<string, int> words_scores;
        for (const string& word : words) {
            int s = 0;
            for (char ch : word) {
                s += score[ch - 'a'];
            }
            words_scores[word] = s;
        }

        function<void(int, int)> recursion = [&](int cur_ind, int cur_score) {
            if (cur_ind == n) {
                res = max(res, cur_score);
                return;
            }

            bool can_add_this_word = true;
            const string& word = words[cur_ind];
            vector<int> word_count(26, 0);
            for (char ch : word) {
                word_count[ch - 'a']++;
                if (word_count[ch - 'a'] > letters_count[ch - 'a']) {
                    can_add_this_word = false;
                    break;
                }
            }

            if (can_add_this_word) {
                for (int i = 0; i < 26; i++) {
                    letters_count[i] -= word_count[i];
                }
                recursion(cur_ind + 1, cur_score + words_scores[word]);
                for (int i = 0; i < 26; i++) {
                    letters_count[i] += word_count[i];
                }
            }
            recursion(cur_ind + 1, cur_score);
        };

        recursion(0, 0);
        return res;
    }
};