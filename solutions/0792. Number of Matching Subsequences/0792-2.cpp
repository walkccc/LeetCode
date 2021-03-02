class Solution {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    int ans = 0;
    // pair (i, j) := words[i] and the character j waiting for
    vector<vector<pair<int, int>>> waiting(26);

    // for each word, it's waiting for word[1]
    for (int i = 0; i < words.size(); ++i)
      waiting[words[i][0] - 'a'].push_back({i, 1});

    for (const char c : S) {
      // clear waiting[c] and take the value of waiting[c] in advance
      vector<pair<int, int>> advance;
      swap(advance, waiting[c - 'a']);
      for (auto& [i, j] : advance)
        if (j == words[i].length())  // all characters in words[i] are matched
          ++ans;
        else
          waiting[words[i][j++] - 'a'].push_back({i, j});
    }

    return ans;
  }
};
