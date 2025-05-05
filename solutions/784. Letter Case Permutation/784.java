class Solution {
  public List<String> letterCasePermutation(String s) {
    List<String> ans = new ArrayList<>();
    dfs(new StringBuilder(s), 0, ans);
    return ans;
  }

  private void dfs(StringBuilder sb, int i, List<String> ans) {
    if (i == sb.length()) {
      ans.add(sb.toString());
      return;
    }
    if (Character.isDigit(sb.charAt(i))) {
      dfs(sb, i + 1, ans);
      return;
    }

    sb.setCharAt(i, Character.toLowerCase(sb.charAt(i)));
    dfs(sb, i + 1, ans);
    sb.setCharAt(i, Character.toUpperCase(sb.charAt(i)));
    dfs(sb, i + 1, ans);
  }
}
