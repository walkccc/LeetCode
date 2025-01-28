class Solution {
 public:
  int wordCount(vector<string>& startWords, vector<string>& targetWords) {
    int ans = 0;
    unordered_set<int> seen;

    for (const string& w : startWords)
      seen.insert(getMask(w));

    for (const string& w : targetWords) {
      const int mask = getMask(w);
      for (const char c : w)
        // Toggle one character.
        if (seen.contains(mask ^ 1 << c - 'a')) {
          ++ans;
          break;
        }
    }

    return ans;
  }

 private:
  int getMask(const string& s) {
    int mask = 0;
    for (const char c : s)
      mask ^= 1 << c - 'a';
    return mask;
  }
};
