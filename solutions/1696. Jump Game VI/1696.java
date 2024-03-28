class Solution {
  public int maxResult(int[] nums, int k) {
    // Stores dp[i] within the bounds.
    Deque<Integer> maxQ = new ArrayDeque<>(Arrays.asList(0));
    // dp[i] := the maximum score to consider nums[0..i]
    int[] dp = new int[nums.length];
    dp[0] = nums[0];

    for (int i = 1; i < nums.length; ++i) {
      // Pop the index if it's out-of-bounds.
      if (maxQ.peekFirst() + k < i)
        maxQ.pollFirst();
      dp[i] = dp[maxQ.peekFirst()] + nums[i];
      // Pop indices that won't be chosen in the future.
      while (!maxQ.isEmpty() && dp[maxQ.peekLast()] <= dp[i])
        maxQ.pollLast();
      maxQ.offerLast(i);
    }

    return dp[nums.length - 1];
  }
}
