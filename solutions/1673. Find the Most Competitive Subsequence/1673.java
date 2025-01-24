class Solution {
  public int[] mostCompetitive(int[] nums, int k) {
    int[] ans = new int[k];
    Deque<Integer> stack = new ArrayDeque<>();

    for (int i = 0; i < nums.length; ++i) {
      // If |stack| - 1 + |nums[i..n)| >= k, then it means we still have enough
      // numbers, and we can safely pop an element from stack.
      while (!stack.isEmpty() && stack.peek() > nums[i] && stack.size() - 1 + nums.length - i >= k)
        stack.pop();
      if (stack.size() < k)
        stack.push(nums[i]);
    }

    for (int i = 0; i < k; i++)
      ans[i] = stack.pollLast();

    return ans;
  }
}
