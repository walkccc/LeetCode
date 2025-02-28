class Solution {
 public:
  vector<int> validSequence(string word1, string word2) {
    vector<int> ans(word2.length());
    // last[j] := the index i of the last occurrence in word1, where
    // word1[i] == word2[j]
    vector<int> last(word2.length(), -1);

    int i = word1.length() - 1;
    int j = word2.length() - 1;
    while (i >= 0 && j >= 0) {
      if (word1[i] == word2[j])
        last[j--] = i;
      --i;
    }

    bool canSkip = true;
    j = 0;
    for (i = 0; i < word1.length(); ++i) {
      if (j == word2.length())
        break;
      if (word1[i] == word2[j]) {
        ans[j++] = i;
      } else if (canSkip && (j == word2.length() - 1 || i < last[j + 1])) {
        canSkip = false;
        ans[j++] = i;
      }
    }

    return j == word2.length() ? ans : vector<int>();
  }
};
