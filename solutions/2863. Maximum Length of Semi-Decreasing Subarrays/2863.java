class Solution {
  public int maxSubarrayLength(int[] nums) {
    int ans = 0;
    Deque<Integer> stack = new ArrayDeque<>();

    for (int i = nums.length - 1; i >= 0; --i)
      // If nums[stack.peek()] <= nums[i], stack.peek() is better than i.
      // So, no need to push it.
      if (stack.isEmpty() || nums[stack.peek()] > nums[i])
        stack.push(i);

    for (int i = 0; i < nums.length; ++i)
      while (!stack.isEmpty() && nums[i] > nums[stack.peek()])
        ans = Math.max(ans, stack.pop() - i + 1);

    return ans;
  }
}
