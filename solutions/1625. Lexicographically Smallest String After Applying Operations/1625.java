class Solution {
  public String findLexSmallestString(String s, int a, int b) {
    ans = s;

    dfs(s, a, b, new HashSet<>());

    return ans;
  }

  private String ans;

  private void dfs(String s, int a, int b, Set<String> seen) {
    if (seen.contains(s))
      return;

    seen.add(s);
    if (ans.compareTo(s) > 0)
      ans = s;

    dfs(add(s, a), a, b, seen);
    dfs(rotate(s, b), a, b, seen);
  }

  private String add(final String s, int a) {
    StringBuilder sb = new StringBuilder(s);
    for (int i = 1; i < sb.length(); i += 2)
      sb.setCharAt(i, (char) ('0' + (s.charAt(i) - '0' + a) % 10));
    return sb.toString();
  }

  private String rotate(final String s, int b) {
    final int n = s.length();
    return s.substring(n - b, n) + s.substring(0, n - b);
  }
}
