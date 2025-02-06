class Solution {
 public:
  int findLUSlength(vector<string>& strs) {
    unordered_set<string> seen;
    unordered_set<string> duplicates;

    for (const string& str : strs)
      if (seen.contains(str))
        duplicates.insert(str);
      else
        seen.insert(str);

    ranges::sort(strs, ranges::greater{},
                 [](const string& s) { return s.length(); });

    for (int i = 0; i < strs.size(); ++i) {
      if (duplicates.contains(strs[i]))
        continue;
      bool isASubsequence = false;
      for (int j = 0; j < i; ++j)
        isASubsequence |= isSubsequence(strs[i], strs[j]);
      if (!isASubsequence)
        return strs[i].length();
    }

    return -1;
  }

 private:
  // Returns true if a is a subsequence of b.
  bool isSubsequence(const string& a, const string& b) {
    int i = 0;
    for (const char c : b)
      if (i < a.length() && c == a[i])
        ++i;
    return i == a.length();
  };
};
