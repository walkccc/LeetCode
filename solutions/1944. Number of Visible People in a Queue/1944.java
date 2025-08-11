class Solution {
  public int[] canSeePersonsCount(int[] heights) {
    final int n = heights.length;
    int[] ans = new int[n];
    Deque<Integer> stack = new ArrayDeque<>();

    for (int i = 0; i < n; ++i) {
      while (!stack.isEmpty() && heights[stack.peek()] <= heights[i])
        ++ans[stack.pop()];
      if (!stack.isEmpty())
        ++ans[stack.peek()];
      stack.push(i);
    }

    return ans;
  }
}
