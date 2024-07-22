class Solution {
  public int maxJumps(int[] arr, int d) {
    final int n = arr.length;
    // dp[i] := the maximum jumps starting from arr[i]
    int[] dp = new int[n];
    // a dcreasing stack that stores indices
    Deque<Integer> stack = new ArrayDeque<>();

    for (int i = 0; i <= n; ++i) {
      while (!stack.isEmpty() && (i == n || arr[stack.peek()] < arr[i])) {
        List<Integer> indices = new ArrayList<>(Arrays.asList(stack.pop()));
        while (!stack.isEmpty() && arr[stack.peek()] == arr[indices.get(0)])
          indices.add(stack.pop());
        for (final int j : indices) {
          if (i < n && i - j <= d)
            // Can jump from i to j.
            dp[i] = Math.max(dp[i], dp[j] + 1);
          if (!stack.isEmpty() && j - stack.peek() <= d)
            // Can jump from stack.peek() to j
            dp[stack.peek()] = Math.max(dp[stack.peek()], dp[j] + 1);
        }
      }
      stack.push(i);
    }

    return Arrays.stream(dp).max().getAsInt() + 1;
  }
}
