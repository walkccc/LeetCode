class Solution {
  public long maximumTotalSum(int[] maximumHeight) {
    long ans = 0;
    int mn = Integer.MAX_VALUE;

    Arrays.sort(maximumHeight);

    for (int i = maximumHeight.length - 1; i >= 0; --i) {
      final int assigned = Math.min(maximumHeight[i], mn - 1);
      if (assigned == 0)
        return -1;
      ans += assigned;
      mn = assigned;
    }

    return ans;
  }
}
