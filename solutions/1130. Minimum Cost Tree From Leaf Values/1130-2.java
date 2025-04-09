class Solution {
  public int mctFromLeafValues(int[] arr) {
    int ans = 0;
    Deque<Integer> stack = new ArrayDeque<>();
    stack.push(Integer.MAX_VALUE);

    for (final int a : arr) {
      while (stack.peek() <= a) {
        final int mid = stack.pop();
        // Multiply mid with next greater element in the array,
        // On the left (stack[-1]) or on the right (current number a)
        ans += Math.min(stack.peek(), a) * mid;
      }
      stack.push(a);
    }

    while (stack.size() > 2)
      ans += stack.pop() * stack.peek();

    return ans;
  }
}
