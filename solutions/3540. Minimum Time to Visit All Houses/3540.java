class Solution {
  public long minTotalTime(int[] forward, int[] backward, int[] queries) {
    final int n = forward.length;
    final long sum = Arrays.stream(backward).asLongStream().sum();
    long ans = 0;
    int pos = 0;
    long[] prefixF = new long[n + 1];
    long[] prefixB = new long[n + 1];

    for (int i = 0; i < n; i++) {
      prefixF[i + 1] = prefixF[i] + forward[i];
      prefixB[i] = (i == 0 ? 0 : prefixB[i - 1]) + backward[i];
    }

    for (final int q : queries) {
      final long r = (q < pos ? prefixF[n] : 0) + prefixF[q] - prefixF[pos];
      final long l = (q > pos ? sum : 0) + prefixB[pos] - prefixB[q];
      ans += Math.min(l, r);
      pos = q;
    }

    return ans;
  }
}
