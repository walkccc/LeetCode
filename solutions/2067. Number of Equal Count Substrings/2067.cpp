class Solution {
 public:
  int equalCountSubstrings(string s, int count) {
    const int maxUnique = unordered_set<int>(s.begin(), s.end()).size();
    int ans = 0;

    for (int unique = 1; unique <= maxUnique; ++unique) {
      const int windowSize = unique * count;
      vector<int> lettersCount(26);
      int uniqueCount = 0;
      for (int i = 0; i < s.length(); ++i) {
        if (++lettersCount[s[i] - 'a'] == count)
          ++uniqueCount;
        if (i >= windowSize &&
            --lettersCount[s[i - windowSize] - 'a'] == count - 1)
          --uniqueCount;
        ans += uniqueCount == unique;
      }
    }

    return ans;
  }
};
