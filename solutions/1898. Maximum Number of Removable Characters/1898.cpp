class Solution {
 public:
  int maximumRemovals(string s, string p, vector<int>& removable) {
    int l = 0;
    int r = removable.size() + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      const string& removed = remove(s, removable, m);
      if (isSubsequence(p, removed))
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }

 private:
  string remove(const string& s, const vector<int>& removable, int k) {
    string removed(s);
    for (int i = 0; i < k; ++i)
      removed[removable[i]] = '*';
    return removed;
  }

  bool isSubsequence(const string& p, const string& s) {
    int i = 0;  // p's index
    for (int j = 0; j < s.length(); ++j)
      if (p[i] == s[j])
        if (++i == p.length())
          return true;
    return false;
  }
};
