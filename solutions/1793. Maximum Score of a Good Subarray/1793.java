class Solution {
  // Similar to 84. Largest Rectangle in Histogram
  public int maximumScore(int[] nums, int k) {
    int ans = 0;
    Deque<Integer> stack = new ArrayDeque<>();

    for (int i = 0; i <= nums.length; ++i) {
      while (!stack.isEmpty() && (i == nums.length || nums[stack.peek()] > nums[i])) {
        final int h = nums[stack.pop()];
        final int w = stack.isEmpty() ? i : i - stack.peek() - 1;
        if ((stack.isEmpty() || stack.peek() + 1 <= k) && i - 1 >= k)
          ans = Math.max(ans, h * w);
      }
      stack.push(i);
    }

    return ans;
  }
}
