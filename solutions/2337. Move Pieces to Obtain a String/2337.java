class Solution {
  public boolean canChange(String start, String target) {
    final int n = start.length();
    int i = 0; // start's index
    int j = 0; // target's index

    while (i <= n && j <= n) {
      while (i < n && start.charAt(i) == '_')
        ++i;
      while (j < n && target.charAt(j) == '_')
        ++j;
      if (i == n || j == n)
        return i == n && j == n;
      if (start.charAt(i) != target.charAt(j))
        return false;
      if (start.charAt(i) == 'R' && i > j)
        return false;
      if (start.charAt(i) == 'L' && i < j)
        return false;
      ++i;
      ++j;
    }

    return true;
  }
}
