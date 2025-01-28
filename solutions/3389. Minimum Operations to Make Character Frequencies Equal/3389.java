class Solution {
  public int makeStringGood(String s) {
    int ans = s.length();
    int[] count = new int[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    final int maxCount = Arrays.stream(count).max().getAsInt();
    for (int target = 1; target <= maxCount; ++target)
      ans = Math.min(ans, getMinOperations(count, target));

    return ans;
  }

  private int getMinOperations(int[] count, int target) {
    // dp[i] represents the minimum number of operations to make the frequency of
    // (i..25)-th (0-indexed) letters equal to `target`.
    int[] dp = new int[27];

    for (int i = 25; i >= 0; --i) {
      // 1. Delete all the i-th letters.
      int deleteAllToZero = count[i];
      // 2. Insert/delete the i-th letters to have `target` number of letters.
      int deleteOrInsertToTarget = Math.abs(target - count[i]);
      dp[i] = Math.min(deleteAllToZero, deleteOrInsertToTarget) + dp[i + 1];
      if (i + 1 < 26 && count[i + 1] < target) {
        final int nextDeficit = target - count[i + 1];
        // Make the frequency of the i-th letter equal to the `target` or 0.
        final int needToChange = count[i] <= target ? count[i] : count[i] - target;
        final int changeToTarget = (nextDeficit > needToChange)
                                       // 3. Change all the i-th letters to the next letter and then
                                       // insert the remaining deficit for the next letter.
                                       ? needToChange + (nextDeficit - needToChange)
                                       // 4. Change `nextDeficit` i-th letters to the next letter
                                       // and then delete the remaining i-th letters.
                                       : nextDeficit + (needToChange - nextDeficit);
        dp[i] = Math.min(dp[i], changeToTarget + dp[i + 2]);
      }
    }

    return dp[0];
  }
}
