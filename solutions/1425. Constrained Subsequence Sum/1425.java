class Solution {
  public int constrainedSubsetSum(int[] nums, int k) {
    // dp[i] := max sum of non-empty subsequence in nums[0..i]
    int[] dp = new int[nums.length];
    // q stores dp[i - k], dp[i - k + 1], ..., dp[i - 1] whose values are > 0 in decreasing order
    Deque<Integer> q = new ArrayDeque<>();

    for (int i = 0; i < nums.length; ++i) {
      if (q.isEmpty())
        dp[i] = nums[i];
      else
        dp[i] = Math.max(q.peekFirst(), 0) + nums[i];
      while (!q.isEmpty() && q.peekLast() < dp[i])
        q.pollLast();
      q.offerLast(dp[i]);
      if (i >= k && dp[i - k] == q.peekFirst())
        q.pollFirst();
    }

    return Arrays.stream(dp).max().getAsInt();
  }
}
