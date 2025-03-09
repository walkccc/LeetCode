class Solution {
  public int[] maximumLengthOfRanges(int[] nums) {
    int[] ans = new int[nums.length];
    Deque<Integer> stack = new ArrayDeque<>(); // a decreasing stack

    for (int i = 0; i <= nums.length; ++i) {
      while (!stack.isEmpty() && (i == nums.length || nums[stack.peek()] < nums[i])) {
        final int index = stack.pop();
        final int left = stack.isEmpty() ? -1 : stack.peek();
        ans[index] = i - left - 1;
      }
      stack.push(i);
    }

    return ans;
  }
}
