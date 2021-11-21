class Solution {
  public int[] dailyTemperatures(int[] T) {
    int[] ans = new int[T.length];
    Stack<Integer> stack = new Stack<>(); // decreasing stack

    for (int i = 0; i < T.length; ++i) {
      while (!stack.isEmpty() && T[stack.peek()] < T[i]) {
        final int index = stack.pop();
        ans[index] = i - index;
      }
      stack.push(i);
    }

    return ans;
  }
}
