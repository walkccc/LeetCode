class Solution {
  public List<String> generateParenthesis(int n) {
    List<String> ans = new ArrayList<>();

    dfs(n, n, new StringBuilder(), ans);

    return ans;
  }

  private void dfs(int l, int r, final StringBuilder path, List<String> ans) {
    if (l == 0 && r == 0) {
      ans.add(path.toString());
      return;
    }

    if (l > 0) {
      path.append("(");
      dfs(l - 1, r, path, ans);
      path.deleteCharAt(path.length() - 1);
    }
    if (l < r) {
      path.append(")");
      dfs(l, r - 1, path, ans);
      path.deleteCharAt(path.length() - 1);
    }
  }
}