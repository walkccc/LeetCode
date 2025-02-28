class Solution {
  public int minZeroArray(int[] nums, int[][] queries) {
    int[] line = new int[nums.length + 1];
    int decrement = 0;
    int k = 0;

    for (int i = 0; i < nums.length; ++i) {
      while (decrement + line[i] < nums[i]) {
        if (k == queries.length)
          return -1;
        final int l = queries[k][0];
        final int r = queries[k][1];
        final int val = queries[k][2];
        ++k;
        if (r < i)
          continue;
        line[Math.max(l, i)] += val;
        line[r + 1] -= val;
      }
      decrement += line[i];
    }

    return k;
  }
}
