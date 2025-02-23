class Solution {
  public int maxDepth(String s) {
    int ans = 0;
    int opened = 0;

    for (final char c : s.toCharArray())
      if (c == '(')
        ans = Math.max(ans, ++opened);
      else if (c == ')')
        --opened;

    return ans;
  }
}
