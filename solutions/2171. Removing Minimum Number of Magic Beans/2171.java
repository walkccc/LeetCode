class Solution {
  public long minimumRemoval(int[] beans) {
    final long n = beans.length;
    final long sum = Arrays.stream(beans).asLongStream().sum();
    long ans = Long.MAX_VALUE;

    Arrays.sort(beans);

    for (int i = 0; i < n; ++i)
      ans = Math.min(ans, sum - (n - i) * beans[i]);

    return ans;
  }
}
