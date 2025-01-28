class Solution {
  // Similar to 857. Minimum Cost to Hire K Workers
  public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
    final int kMod = 1_000_000_007;
    long ans = 0;
    long speedSum = 0;
    // (efficiency[i], speed[i]) sorted by efficiency[i] in descending order
    Pair<Integer, Integer>[] A = new Pair[n];
    Queue<Integer> minHeap = new PriorityQueue<>();

    for (int i = 0; i < n; ++i)
      A[i] = new Pair<>(efficiency[i], speed[i]);

    Arrays.sort(A, (a, b) -> b.getKey().compareTo(a.getKey()));

    for (Pair<Integer, Integer> a : A) {
      final int e = a.getKey();
      final int s = a.getValue();
      minHeap.offer(s);
      speedSum += s;
      if (minHeap.size() > k)
        speedSum -= minHeap.poll();
      ans = Math.max(ans, speedSum * e);
    }

    return (int) (ans % kMod);
  }
}
