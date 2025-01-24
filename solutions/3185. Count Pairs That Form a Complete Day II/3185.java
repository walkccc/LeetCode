class Solution {
  // Same as 3184. Count Pairs That Form a Complete Day I
  public long countCompleteDayPairs(int[] hours) {
    long ans = 0;
    int[] count = new int[24];

    for (final int hour : hours) {
      ans += count[(24 - hour % 24) % 24];
      ++count[hour % 24];
    }

    return ans;
  }
}
