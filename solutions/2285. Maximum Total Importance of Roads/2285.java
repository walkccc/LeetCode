class Solution {
  public long maximumImportance(int n, int[][] roads) {
    long ans = 0;
    long[] count = new long[n];

    for (int[] r : roads) {
      ++count[r[0]];
      ++count[r[1]];
    }

    Arrays.sort(count);

    for (int i = 0; i < n; ++i)
      ans += (i + 1) * count[i];

    return ans;
  }
}
