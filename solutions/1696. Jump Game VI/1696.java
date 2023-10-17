class Solution {
  public int maxResult(int[] nums, int k) {
    // max queue storing dp[i] within the bounds
    Deque<Integer> dq = new ArrayDeque<>(Arrays.asList(0));
    // dp[i] := max score to consider nums[0..i]
    int[] dp = new int[nums.length];
    dp[0] = nums[0];

    for (int i = 1; i < nums.length; ++i) {
      // Pop the index if it's out of bounds.
      if (dq.peekFirst() + k < i)
        dq.pollFirst();
      dp[i] = dp[dq.peekFirst()] + nums[i];
      // Pop indices that won't be chosen in the future.
      while (!dq.isEmpty() && dp[dq.peekLast()] <= dp[i])
        dq.pollLast();
      dq.offerLast(i);
    }

    return dp[nums.length - 1];
  }
}
