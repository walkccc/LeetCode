class Solution {
  public List<String> validStrings(int n) {
    List<String> ans = new ArrayList<>();
    dfs(n, new StringBuilder(), ans);
    return ans;
  }

  private void dfs(int n, StringBuilder s, List<String> ans) {
    if (n == 0) {
      ans.add(s.toString());
      return;
    }
    if (s.isEmpty() || s.charAt(s.length() - 1) == '1') {
      s.append('0');
      dfs(n - 1, s, ans);
      s.deleteCharAt(s.length() - 1);
    }
    s.append('1');
    dfs(n - 1, s, ans);
    s.deleteCharAt(s.length() - 1);
  }
}
