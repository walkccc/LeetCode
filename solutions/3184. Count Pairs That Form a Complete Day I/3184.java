class Solution {
  public int countCompleteDayPairs(int[] hours) {
    int ans = 0;
    int[] count = new int[24];

    for (final int hour : hours) {
      ans += count[(24 - hour % 24) % 24];
      ++count[hour % 24];
    }

    return ans;
  }
}
