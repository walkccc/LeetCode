class Solution {
  public int minOperations(int[] nums) {
    int ans = 0;
    Deque<Integer> stack = new ArrayDeque<>();
    stack.push(0);

    for (final int num : nums) {
      while (!stack.isEmpty() && stack.peek() > num)
        stack.pop();
      if (stack.isEmpty() || stack.peek() < num) {
        ++ans;
        stack.push(num);
      }
    }

    return ans;
  }
}
