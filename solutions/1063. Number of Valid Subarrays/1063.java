class Solution {
  public int validSubarrays(int[] nums) {
    // For each num in nums, each element x in the stack can be the leftmost
    // Element s.t. [x, num] forms a valid subarray, so the stack.size() is
    // The # of valid subarrays ending at curr num
    //
    // E.g. nums = [1, 3, 2]
    // Num = 1, stack = [1] -> valid subarray is [1]
    // Num = 3, stack = [1, 3] -> valid subarrays are [1, 3], [3]
    // Num = 2, stack = [1, 2] -> valid subarrays are [1, 3, 2], [2]
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
