class Solution {
 public:
  vector<int> findPermutation(string s) {
    vector<int> ans(s.length() + 1);

    iota(ans.begin(), ans.end(), 1);

    // For each D* group (s[i..j]), reverse ans[i..j + 1].
    int i = -1;
    int j = -1;

    while (true) {
      i = getNextIndex(s, 'D', j + 1);
      if (i == s.length())
        break;
      j = getNextIndex(s, 'I', i + 1);
      reverse(ans.begin() + i, ans.begin() + j + 1);
    }

    return ans;
  }

 private:
  int getNextIndex(const string& s, char c, int start) {
    for (int i = start; i < s.length(); ++i)
      if (s[i] == c)
        return i;
    return s.length();
  }
};
