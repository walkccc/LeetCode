class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;

    function<void(int)> dfs = [&](int start) {
      if (start == s.length()) {
        ans.push_back(path);
        return;
      }

      for (int i = start; i < s.length(); ++i)
        if (isPalindrome(s, start, i)) {
          path.push_back(s.substr(start, i - start + 1));
          dfs(i + 1);
          path.pop_back();
        }
    };

    dfs(0);

    return ans;
  }

 private:
  bool isPalindrome(const string& s, int l, int r) {
    while (l < r)
      if (s[l++] != s[r--])
        return false;
    return true;
  }
};