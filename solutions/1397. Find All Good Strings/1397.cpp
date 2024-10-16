class Solution {
 public:
  int findGoodStrings(int n, string s1, string s2, string evil) {
    vector<vector<vector<vector<int>>>> mem(
        n, vector<vector<vector<int>>>(
               evil.length(), vector<vector<int>>(2, vector<int>(2, -1))));
    // nextMatchedCount[i][j] := the number of next matched evil count, where
    // there're i matches with `evil` and the current letter is ('a' + j)
    vector<vector<int>> nextMatchedCount(evil.length(), vector<int>(26, -1));
    return count(s1, s2, evil, 0, 0, true, true, getLPS(evil), nextMatchedCount,
                 mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of good strings for s[i..n), where there're j matches
  // with `evil`, `isS1Prefix` indicates if the current letter is tightly bound
  // for `s1` and `isS2Prefix` indicates if the current letter is tightly bound
  // for `s2`.
  int count(const string& s1, const string& s2, const string& evil, int i,
            int matchedEvilCount, bool isS1Prefix, bool isS2Prefix,
            const vector<int>& evilLPS, vector<vector<int>>& nextMatchedCount,
            vector<vector<vector<vector<int>>>>& mem) {
    // s[0..i) contains `evil`, so don't consider any ongoing strings.
    if (matchedEvilCount == evil.length())
      return 0;
    // Run out of strings, so contribute one.
    if (i == s1.length())
      return 1;
    int& res = mem[i][matchedEvilCount][isS1Prefix][isS2Prefix];
    if (res != -1)
      return res;
    res = 0;
    const char minLetter = isS1Prefix ? s1[i] : 'a';
    const char maxLetter = isS2Prefix ? s2[i] : 'z';
    for (char c = minLetter; c <= maxLetter; ++c) {
      const int nextMatchedEvilCount = getNextMatchedEvilCount(
          nextMatchedCount, evil, matchedEvilCount, c, evilLPS);
      res += count(s1, s2, evil, i + 1, nextMatchedEvilCount,
                   isS1Prefix && c == s1[i], isS2Prefix && c == s2[i], evilLPS,
                   nextMatchedCount, mem);
      res %= kMod;
    }
    return res;
  }

  // Returns the lps array, where lps[i] is the length of the longest prefix of
  // pattern[0..i] which is also a suffix of this substring.
  vector<int> getLPS(const string& pattern) {
    vector<int> lps(pattern.length());
    for (int i = 1, j = 0; i < pattern.length(); ++i) {
      while (j > 0 && pattern[j] != pattern[i])
        j = lps[j - 1];
      if (pattern[i] == pattern[j])
        lps[i] = ++j;
    }
    return lps;
  }

  // j := the next index we're trying to match with `currLetter`
  int getNextMatchedEvilCount(vector<vector<int>>& nextMatchedCount,
                              const string& evil, int j, char currLetter,
                              const vector<int>& evilLPS) {
    int& res = nextMatchedCount[j][currLetter - 'a'];
    if (res != -1)
      return res;
    while (j > 0 && evil[j] != currLetter)
      j = evilLPS[j - 1];
    return res = (evil[j] == currLetter ? j + 1 : j);
  }
};
