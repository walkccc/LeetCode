class Solution {
  public List<String> removeInvalidParentheses(String s) {
    List<String> ans = new ArrayList<>();
    final int[] counts = getLeftAndRightCounts(s);
    dfs(s, 0, counts[0], counts[1], ans);
    return ans;
  }

  // Similar to 921. Minimum Add to Make Parentheses Valid
  // Returns how many '(' and ')' need to be deleted.
  private int[] getLeftAndRightCounts(final String s) {
    int l = 0;
    int r = 0;

    for (final char c : s.toCharArray())
      if (c == '(')
        ++l;
      else if (c == ')') {
        if (l == 0)
          ++r;
        else
          --l;
      }

    return new int[] {l, r};
  }

  private void dfs(final String s, int start, int l, int r, List<String> ans) {
    if (l == 0 && r == 0 && isValid(s)) {
      ans.add(s);
      return;
    }

    for (int i = start; i < s.length(); ++i) {
      if (i > start && s.charAt(i) == s.charAt(i - 1))
        continue;
      if (l > 0 && s.charAt(i) == '(') // Delete s[i].
        dfs(s.substring(0, i) + s.substring(i + 1), i, l - 1, r, ans);
      else if (r > 0 && s.charAt(i) == ')') // Delete s[i].
        dfs(s.substring(0, i) + s.substring(i + 1), i, l, r - 1, ans);
    }
  }

  private boolean isValid(final String s) {
    int opened = 0; // the number of '(' - # of ')'
    for (final char c : s.toCharArray()) {
      if (c == '(')
        ++opened;
      else if (c == ')')
        --opened;
      if (opened < 0)
        return false;
    }
    return true; // opened == 0
  }
}
