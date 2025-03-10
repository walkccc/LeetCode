class Solution {
  public int[] findBuildings(int[] heights) {
    Deque<Integer> stack = new ArrayDeque<>();

    for (int i = 0; i < heights.length; ++i) {
      while (!stack.isEmpty() && heights[stack.peek()] <= heights[i])
        stack.pop();
      stack.push(i);
    }

    int[] ans = new int[stack.size()];
    for (int i = 0; i < ans.length; ++i)
      ans[ans.length - 1 - i] = stack.pop();
    return ans;
  }
}
