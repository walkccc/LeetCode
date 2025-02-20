class Solution {
  public boolean find132pattern(int[] nums) {
    Deque<Integer> stack = new ArrayDeque<>(); // a decreasing stack
    int ak = Integer.MIN_VALUE;                // Find a seq, where ai < ak < aj.

    for (int i = nums.length - 1; i >= 0; --i) {
      // ai < ak, done because ai must < aj.
      if (nums[i] < ak)
        return true;
      while (!stack.isEmpty() && stack.peek() < nums[i])
        ak = stack.pop();
      stack.push(nums[i]); // `nums[i]` is a candidate of aj.
    }

    return false;
  }
}
