class Solution {
 public:
  int maxProduct(string s) {
    size_t ans = 0;
    dfs(s, 0, "", "", ans);
    return ans;
  }

 private:
  void dfs(const string& s, int i, string&& s1, string&& s2, size_t& ans) {
    if (i == s.length()) {
      if (isPalindrome(s1) && isPalindrome(s2))
        ans = max(ans, s1.length() * s2.length());
      return;
    }

    s1.push_back(s[i]);
    dfs(s, i + 1, move(s1), move(s2), ans);
    s1.pop_back();

    s2.push_back(s[i]);
    dfs(s, i + 1, move(s1), move(s2), ans);
    s2.pop_back();

    dfs(s, i + 1, move(s1), move(s2), ans);
  }

  bool isPalindrome(const string& s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
      if (s[i] != s[j])
        return false;
      ++i;
      --j;
    }
    return true;
  }
};
