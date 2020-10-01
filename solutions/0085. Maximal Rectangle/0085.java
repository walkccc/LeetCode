class Solution {
  public int maximalRectangle(char[][] matrix) {
    if (matrix.length == 0)
      return 0;

    int ans = 0;
    int[] temp = new int[matrix[0].length];

    for (char[] row : matrix) {
      for (int i = 0; i < row.length; ++i)
        temp[i] = row[i] == '0' ? 0 : temp[i] + 1;
      ans = Math.max(ans, largestRectangleArea(temp));
    }

    return ans;
  }

  private int largestRectangleArea(int[] heights) {
    int ans = 0;
    Stack<Integer> stack = new Stack<>();

    for (int i = 0; i <= heights.length; ++i) {
      while (!stack.isEmpty() && (i == heights.length || heights[stack.peek()] > heights[i])) {
        final int h = heights[stack.pop()];
        final int w = stack.isEmpty() ? i : i - stack.peek() - 1;
        ans = Math.max(ans, h * w);
      }
      stack.push(i);
    }

    return ans;
  }
}