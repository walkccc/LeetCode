class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string path;

    dfs(n, n, path, ans);

    return ans;
  }

 private:
  void dfs(int l, int r, string& path, vector<string>& ans) {
    if (l == 0 && r == 0) {
      ans.push_back(path);
      return;
    }

    if (l > 0) {
      path.push_back('(');
      dfs(l - 1, r, path, ans);
      path.pop_back();
    }
    if (l < r) {
      path.push_back(')');
      dfs(l, r - 1, path, ans);
      path.pop_back();
    }
  }
};
