class Solution {
  // Same as 926. Flip String to Monotone Increasing
  public int minimumDeletions(String s) {
    // the number of characters to be deleted to make subString so far balanced
    int dp = 0;
    int countB = 0;

    for (final char c : s.toCharArray())
      if (c == 'a')
        // 1. Delete 'a'.
        // 2. Keep 'a' and delete the previous 'b's.
        dp = Math.min(dp + 1, countB);
      else
        ++countB;

    return dp;
  }
}
