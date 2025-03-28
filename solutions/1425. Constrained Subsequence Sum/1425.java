class Solution {
  public int constrainedSubsetSum(int[] nums, int k) {
    // dp[i] := the maximum the sum of non-empty subsequences in nums[0..i]
    int[] dp = new int[nums.length];
    // dq stores dp[i - k], dp[i - k + 1], ..., dp[i - 1] whose values are > 0
    // in decreasing order.
    Deque<Integer> dq = new ArrayDeque<>();

    for (int i = 0; i < nums.length; ++i) {
      if (dq.isEmpty())
        dp[i] = nums[i];
      else
        dp[i] = Math.max(dq.peekFirst(), 0) + nums[i];
      while (!dq.isEmpty() && dq.peekLast() < dp[i])
        dq.pollLast();
      dq.offerLast(dp[i]);
      if (i >= k && dp[i - k] == dq.peekFirst())
        dq.pollFirst();
    }

    return Arrays.stream(dp).max().getAsInt();
  }
}
