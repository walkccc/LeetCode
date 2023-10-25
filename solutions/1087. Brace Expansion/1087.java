class Solution {
  public String[] expand(String s) {
    List<String> ans = new ArrayList<>();

    dfs(s, 0, new StringBuilder(), ans);
    Collections.sort(ans);
    return ans.toArray(new String[0]);
  }

  private void dfs(final String s, int i, StringBuilder sb, List<String> ans) {
    if (i == s.length()) {
      ans.add(sb.toString());
      return;
    }
    if (s.charAt(i) == '{') {
      final int nextRightBraceIndex = s.indexOf("}", i);
      for (final String c : s.substring(i + 1, nextRightBraceIndex).split(",")) {
        sb.append(c);
        dfs(s, nextRightBraceIndex + 1, sb, ans);
        sb.deleteCharAt(sb.length() - 1);
      }
    } else { // s[i] != '{'
      sb.append(s.charAt(i));
      dfs(s, i + 1, sb, ans);
      sb.deleteCharAt(sb.length() - 1);
    }
  }
}
