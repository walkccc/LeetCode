class Solution {
 public:
  int shortestMatchingSubstring(string s, string p) {
    const auto [a, b, c] = split(p);
    const int ns = s.length();
    const int na = a.length();
    const int nb = b.length();
    const int nc = c.length();
    const vector<int> lpsA = getLPS(a + '#' + s);
    const vector<int> lpsB = getLPS(b + '#' + s);
    const vector<int> lpsC = getLPS(c + '#' + s);
    int ans = INT_MAX;

    for (int i = 0, j = 0, k = 0; i + nb + nc < ns; ++i) {
      while (i < ns && lpsA[na + 1 + i] != na)
        ++i;
      while (j < ns && (j < i + nb || lpsB[nb + 1 + j] != nb))
        ++j;
      while (k < ns && (k < j + nc || lpsC[nc + 1 + k] != nc))
        ++k;
      if (k == ns)
        break;
      ans = min(ans, k - i + na);
    }

    return ans == INT_MAX ? -1 : ans;
  }

 private:
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

  tuple<string, string, string> split(const string& p) {
    const int i = p.find('*');
    const int j = p.find('*', i + 1);
    return {p.substr(0, i), p.substr(i + 1, j - i - 1), p.substr(j + 1)};
  }
};
