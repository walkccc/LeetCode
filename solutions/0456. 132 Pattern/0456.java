class Solution {
  public boolean find132pattern(int[] nums) {
    Deque<Integer> stack = new ArrayDeque<>(); // max stack
    int ak = Integer.MIN_VALUE;                // we want to find a seq ai < ak < aj

    for (int i = nums.length - 1; i >= 0; --i) {
      if (nums[i] < ak) // ai < ak, we're done because ai must also smaller than aj
        return true;
      while (!stack.isEmpty() && stack.peek() < nums[i])
        ak = stack.pop();
      stack.push(nums[i]); // nums[i] is a candidate of aj
    }

    return false;
  }
}
