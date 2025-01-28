class Solution {
  public int[][] seePeople(int[][] heights) {
    final int m = heights.length;
    final int n = heights[0].length;
    int[][] ans = new int[m][n];

    for (int i = 0; i < m; ++i) {
      Deque<Integer> stack = new ArrayDeque<>();
      for (int j = 0; j < n; ++j) {
        boolean hasEqualHeight = false;
        while (!stack.isEmpty() && heights[i][stack.peek()] <= heights[i][j]) {
          if (heights[i][stack.peek()] == heights[i][j])
            // edge case: [4, 2, 1, 1, 3]
            hasEqualHeight = true;
          ++ans[i][stack.pop()];
        }
        if (!stack.isEmpty() && !hasEqualHeight)
          ++ans[i][stack.peek()];
        stack.push(j);
      }
    }

    for (int j = 0; j < n; ++j) {
      Deque<Integer> stack = new ArrayDeque<>();
      for (int i = 0; i < m; ++i) {
        boolean hasEqualHeight = false;
        while (!stack.isEmpty() && heights[stack.peek()][j] <= heights[i][j]) {
          if (heights[stack.peek()][j] == heights[i][j])
            hasEqualHeight = true;
          ++ans[stack.pop()][j];
        }
        if (!stack.isEmpty() && !hasEqualHeight)
          ++ans[stack.peek()][j];
        stack.push(i);
      }
    }

    return ans;
  }
}
