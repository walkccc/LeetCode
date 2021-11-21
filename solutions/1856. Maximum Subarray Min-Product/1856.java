class Solution {
  public int maxSumMinProduct(int[] nums) {
    final long kMod = (long) 1e9 + 7;

    long ans = 0;
    Stack<Integer> stack = new Stack<>();
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
