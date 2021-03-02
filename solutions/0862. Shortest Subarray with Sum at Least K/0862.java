class Solution {
  public int shortestSubarray(int[] A, int K) {
    final int n = A.length;

    int ans = n + 1;
    Deque<Integer> deque = new ArrayDeque<>();
    int[] prefix = new int[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = A[i] + prefix[i];

    for (int i = 0; i < n + 1; ++i) {
      while (!deque.isEmpty() && prefix[i] - prefix[deque.getFirst()] >= K)
        ans = Math.min(ans, i - deque.pollFirst());
      while (!deque.isEmpty() && prefix[i] <= prefix[deque.getLast()])
        deque.pollLast();
      deque.addLast(i);
    }

    return ans <= n ? ans : -1;
  }
}
