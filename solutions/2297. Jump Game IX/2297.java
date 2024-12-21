class Solution {
  public long minCost(int[] nums, int[] costs) {
    final int n = nums.length;
    // dp[i] := the minimum cost to jump to i
    long[] dp = new long[n];
    Deque<Integer> maxStack = new ArrayDeque<>();
    Deque<Integer> minStack = new ArrayDeque<>();

    Arrays.fill(dp, Long.MAX_VALUE);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
      while (!maxStack.isEmpty() && nums[i] >= nums[maxStack.peek()])
        dp[i] = Math.min(dp[i], dp[maxStack.pop()] + costs[i]);
      while (!minStack.isEmpty() && nums[i] < nums[minStack.peek()])
        dp[i] = Math.min(dp[i], dp[minStack.pop()] + costs[i]);
      maxStack.push(i);
      minStack.push(i);
    }

    return dp[n - 1];
  }
}
