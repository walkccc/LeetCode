class Solution {
 public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> ans;
    const vector<int> indicesA = kmp(s, a);
    const vector<int> indicesB = kmp(s, b);
    int indicesBIndex = 0;  // indicesB's index

    for (const int i : indicesA) {
      // The constraint is: |j - i| <= k. So, -k <= j - i <= k. So, move
      // `indicesBIndex` s.t. j - i >= -k, where j := indicesB[indicesBIndex].
      while (indicesBIndex < indicesB.size() &&
             indicesB[indicesBIndex] - i < -k)
        ++indicesBIndex;
      if (indicesBIndex < indicesB.size() && indicesB[indicesBIndex] - i <= k)
        ans.push_back(i);
    }

    return ans;
  }

 private:
  // Returns the starting indices of all occurrences of the pattern in `s`.
  vector<int> kmp(const string& s, const string& pattern) {
    vector<int> res;
    const vector<int> lps = getLPS(pattern);
    int i = 0;  // s's index
    int j = 0;  // pattern's index
    while (i < s.length()) {
      if (s[i] == pattern[j]) {
        ++i;
        ++j;
        if (j == pattern.length()) {
          res.push_back(i - j);
          j = lps[j - 1];
        }
      }
      // Mismatch after j matches.
      else if (j > 0) {
        // Don't match lps[0..lps[j - 1]] since they will match anyway.
        j = lps[j - 1];
      } else {
        ++i;
      }
    }
    return res;
  }

  // Returns the lps array, where lps[i] is the length of the longest prefix of
  // s[0..i] which is also a suffix of this substring.
  vector<int> getLPS(const string& s) {
    vector<int> lps(s.length());
    for (int i = 1, j = 0; i < s.length(); ++i) {
      while (j > 0 && s[j] != s[i])
        j = lps[j - 1];
      if (s[i] == s[j])
        lps[i] = ++j;
    }
    return lps;
  }
};
