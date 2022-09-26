class Solution {
 public:
  int maxScoreWords(vector<string>& words, vector<char>& letters,
                    vector<int>& score) {
    vector<int> count(26);
    for (const char c : letters)
      ++count[c - 'a'];
    return dfs(words, 0, count, score);
  }

 private:
  // max score you can get from words[s:]
  int dfs(const vector<string>& words, int s, vector<int>& count,
          const vector<int>& score) {
    int ans = 0;
    for (int i = s; i < words.size(); ++i) {
      const int earned = useWord(words, i, count, score);
      if (earned > 0)
        ans = max(ans, earned + dfs(words, i + 1, count, score));
      unuseWord(words, i, count);
    }
    return ans;
  }

  int useWord(const vector<string>& words, int i, vector<int>& count,
              const vector<int>& score) {
    bool isValid = true;
    int earned = 0;
    for (const char c : words[i]) {
      if (--count[c - 'a'] < 0)
        isValid = false;
      earned += score[c - 'a'];
    }
    return isValid ? earned : -1;
  }

  void unuseWord(const vector<string>& words, int i, vector<int>& count) {
    for (const char c : words[i])
      ++count[c - 'a'];
  }
};
