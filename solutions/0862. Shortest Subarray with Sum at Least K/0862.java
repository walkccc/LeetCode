class Solution {
  public int shortestSubarray(int[] A, int K) {
    final int n = A.length;
    int ans = n + 1;
    Deque<Integer> q = new ArrayDeque<>();
    long[] prefix = new long[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = (long) A[i] + prefix[i];

    for (int i = 0; i < n + 1; ++i) {
      while (!q.isEmpty() && prefix[i] - prefix[q.getFirst()] >= K)
        ans = Math.min(ans, i - q.pollFirst());
      while (!q.isEmpty() && prefix[i] <= prefix[q.getLast()])
        q.pollLast();
      q.addLast(i);
    }

    return ans <= n ? ans : -1;
  }
}
