class Solution {
  public int validSubarrays(int[] nums) {
    // For each `num` in `nums`, each element x in the stack can be the leftmost
    // element s.t. [x, num] forms a valid subarray, so the size of the stack is
    // the number of valid subarrays ending in the current number.
    //
    // e.g. nums = [1, 3, 2]
    // num = 1, stack = [1] -> valid subarray is [1]
    // num = 3, stack = [1, 3] -> valid subarrays are [1, 3], [3]
    // num = 2, stack = [1, 2] -> valid subarrays are [1, 3, 2], [2]
    int ans = 0;
    Deque<Integer> stack = new ArrayDeque<>();

    for (final int num : nums) {
      while (!stack.isEmpty() && stack.peek() > num)
        stack.pop();
      stack.push(num);
      ans += stack.size();
    }

    return ans;
  }
}
