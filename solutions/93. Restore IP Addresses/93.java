class Solution {
  public List<String> restoreIpAddresses(final String s) {
    List<String> ans = new ArrayList<>();
    dfs(s, 0, new ArrayList<>(), ans);
    return ans;
  }

  private void dfs(final String s, int start, List<String> path, List<String> ans) {
    if (path.size() == 4 && start == s.length()) {
      ans.add(String.join(".", path));
      return;
    }
    if (path.size() == 4 || start == s.length())
      return;

    for (int length = 1; length <= 3; ++length) {
      if (start + length > s.length()) // out-of-bounds
        return;
      if (length > 1 && s.charAt(start) == '0') // leading '0'
        return;
      final String num = s.substring(start, start + length);
      if (Integer.parseInt(num) > 255)
        return;
      path.add(num);
      dfs(s, start + length, path, ans);
      path.remove(path.size() - 1);
    }
  }
}
