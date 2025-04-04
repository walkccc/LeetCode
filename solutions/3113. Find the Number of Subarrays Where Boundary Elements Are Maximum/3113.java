class Solution {
  public long numberOfSubarrays(int[] nums) {
    Deque<int[]> stack = new ArrayDeque<>();
    long ans = 0;
    int top = -1;

    for (final int num : nums) {
      while (!stack.isEmpty() && stack.peek()[0] < num)
        stack.pop();
      if (stack.isEmpty() || stack.peek()[0] != num)
        stack.push(new int[] {num, 0});
      ans += ++stack.peek()[1];
    }

    return ans;
  }
}
