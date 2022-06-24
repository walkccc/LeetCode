class Solution {
  public int[] nextGreaterElements(int[] nums) {
    final int n = nums.length;
    int[] ans = new int[n];
    Arrays.fill(ans, -1);
    Deque<Integer> stack = new ArrayDeque<>(); // decreasing stack storing indices

    for (int i = 0; i < n * 2; ++i) {
      final int num = nums[i % n];
      while (!stack.isEmpty() && nums[stack.peek()] < num)
        ans[stack.pop()] = num;
      if (i < n)
        stack.push(i);
    }

    return ans;
  }
}
