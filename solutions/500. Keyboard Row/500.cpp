class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    vector<string> ans;
    const vector<int> rows{2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3,
                           3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};

    for (const string& word : words) {
      string lowerWord = word;
      ranges::transform(lowerWord, lowerWord.begin(), ::tolower);
      const int row = rows[lowerWord[0] - 'a'];
      const bool isValid = ranges::all_of(
          lowerWord, [&](int c) { return rows[c - 'a'] == row; });
      if (isValid)
        ans.push_back(word);
    }

    return ans;
  }
};
