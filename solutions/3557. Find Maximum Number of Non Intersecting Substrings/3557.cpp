class Solution {
 public:
  int maxSubstrings(string word) {
    int ans = 0;
    unordered_map<char, int> firstSeen;

    for (int i = 0; i < word.length(); ++i) {
      const char c = word[i];
      if (!firstSeen.contains(c)) {
        firstSeen[c] = i;
      } else if (i - firstSeen[c] + 1 >= 4) {
        ++ans;
        firstSeen.clear();
      }
    }

    return ans;
  }
};
