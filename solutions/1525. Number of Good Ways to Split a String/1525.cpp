class Solution {
 public:
  int numSplits(string s) {
    const int n = s.length();
    int ans = 0;
    // prefix[i] := the number of unique letters in s[0..i]
    vector<int> prefix(n);
    // suffix[i] := of unique letters in s[i..n)
    vector<int> suffix(n);
    unordered_set<int> seen;

    for (int i = 0; i < n; ++i) {
      seen.insert(s[i]);
      prefix[i] = seen.size();
    }

    seen.clear();

    for (int i = n - 1; i >= 0; --i) {
      seen.insert(s[i]);
      suffix[i] = seen.size();
    }

    for (int i = 0; i + 1 < n; ++i)
      if (prefix[i] == suffix[i + 1])
        ++ans;

    return ans;
  }
};
