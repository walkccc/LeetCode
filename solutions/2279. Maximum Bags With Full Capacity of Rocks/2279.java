class Solution {
  public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
    final int n = capacity.length;
    int[] diff = new int[n];

    for (int i = 0; i < n; ++i)
      diff[i] = capacity[i] - rocks[i];

    Arrays.sort(diff);

    for (int i = 0; i < n; ++i) {
      if (diff[i] > additionalRocks)
        return i;
      additionalRocks -= diff[i];
    }

    return n;
  }
}
