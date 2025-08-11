class Solution {
 public:
  vector<string> validStrings(int n) {
    vector<string> ans;
    dfs(n, "", ans);
    return ans;
  }

 private:
  void dfs(int n, string&& s, vector<string>& ans) {
    if (n == 0) {
      ans.push_back(s);
      return;
    }
    if (s.empty() || s.back() == '1') {
      s.push_back('0');
      dfs(n - 1, std::move(s), ans);
      s.pop_back();
    }
    s.push_back('1');
    dfs(n - 1, std::move(s), ans);
    s.pop_back();
  }
};
