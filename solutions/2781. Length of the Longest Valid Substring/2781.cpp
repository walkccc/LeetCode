class Solution {
 public:
  int longestValidSubstring(string word, vector<string>& forbidden) {
    int ans = 0;
    unordered_set<string> forbiddenSet{forbidden.begin(), forbidden.end()};

    // r is the rightmost index to make word[l..r] a valid substring.
    int r = word.length() - 1;
    for (int l = word.length() - 1; l >= 0; --l) {
      for (int end = l; end < min(l + 10, r + 1); ++end)
        if (forbiddenSet.count(word.substr(l, end - l + 1))) {
          r = end - 1;
          break;
        }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
