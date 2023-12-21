class Solution {
  public int totalSteps(int[] nums) {
    // dp[i] := the number of steps to remove nums[i]
    int[] dp = new int[nums.length];
    Deque<Integer> stack = new ArrayDeque<>();

    for (int i = 0; i < nums.length; ++i) {
      int step = 1;
      while (!stack.isEmpty() && nums[stack.peek()] <= nums[i])
        step = Math.max(step, dp[stack.pop()] + 1);
      if (!stack.isEmpty())
        dp[i] = step;
      stack.push(i);
    }

    return Arrays.stream(dp).max().getAsInt();
  }
}
