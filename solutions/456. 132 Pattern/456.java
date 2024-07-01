class Solution {
  public boolean find132pattern(int[] nums) {
    Deque<Integer> stack = new ArrayDeque<>(); // a decreasing stack
    int ak = Integer.MIN_VALUE;                // We want to find a seq ai < ak < aj.

    for (int i = nums.length - 1; i >= 0; --i) {
      // ai < ak, we're done because ai must also smaller than aj
      if (nums[i] < ak)
        return true;
      while (!stack.isEmpty() && stack.peek() < nums[i])
        ak = stack.pop();
      stack.push(nums[i]); // `nums[i]` is a candidate of aj.
    }

    return false;
  }
}
