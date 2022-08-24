class Solution {
  public int numSubmat(int[][] mat) {
    final int m = mat.length;
    final int n = mat[0].length;
    int ans = 0;
    int[] hist = new int[n];

    for (int[] row : mat) {
      for (int i = 0; i < row.length; ++i)
        hist[i] = row[i] == 0 ? 0 : hist[i] + 1;
      ans += count(hist);
    }

    return ans;
  }

  private int count(int[] A) {
    // submatrices[i] := # of submatrices w/ column i as the right border
    int[] submatrices = new int[A.length];
    Deque<Integer> stack = new ArrayDeque<>();

    for (int i = 0; i < A.length; ++i) {
      while (!stack.isEmpty() && A[stack.peek()] >= A[i])
        stack.pop();
      if (!stack.isEmpty()) {
        final int prevIndex = stack.peek();
        submatrices[i] = submatrices[prevIndex] + A[i] * (i - prevIndex);
      } else {
        submatrices[i] = A[i] * (i + 1);
      }
      stack.push(i);
    }

    return Arrays.stream(submatrices).sum();
  }
}
