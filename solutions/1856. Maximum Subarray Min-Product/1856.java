class Solution {
  public int maxSumMinProduct(int[] nums) {
    final int kMod = 1_000_000_007;
    long ans = 0;
    Deque<Integer> stack = new ArrayDeque<>();
    long[] prefix = new long[nums.length + 1];

    for (int i = 0; i < nums.length; ++i)
      prefix[i + 1] = prefix[i] + nums[i];

    for (int i = 0; i <= nums.length; ++i) {
      while (!stack.isEmpty() && (i == nums.length || nums[stack.peek()] > nums[i])) {
        final int minVal = nums[stack.pop()];
        final long sum = stack.isEmpty() ? prefix[i] : prefix[i] - prefix[stack.peek() + 1];
        ans = Math.max(ans, minVal * sum);
      }
      stack.push(i);
    }

    return (int) (ans % kMod);
  }
}
