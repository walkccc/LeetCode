class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    dfs(s, 0, {}, ans);
    return ans;
  }

 private:
  void dfs(const string& s, int start, vector<string>&& path,
           vector<vector<string>>& ans) {
    if (start == s.length()) {
      ans.push_back(path);
      return;
    }

    for (int i = start; i < s.length(); ++i)
      if (isPalindrome(s, start, i)) {
        path.push_back(s.substr(start, i - start + 1));
        dfs(s, i + 1, move(path), ans);
        path.pop_back();
      }
  }

  bool isPalindrome(const string& s, int l, int r) {
    while (l < r)
      if (s[l++] != s[r--])
        return false;
    return true;
  }
};
