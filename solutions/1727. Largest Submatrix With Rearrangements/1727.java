class Solution {
  public int largestSubmatrix(int[][] matrix) {
    final int n = matrix[0].length;
    int ans = 0;
    int[] hist = new int[n];

    for (int[] row : matrix) {
      // Accumulate the histogram if possible.
      for (int i = 0; i < n; ++i)
        hist[i] = row[i] == 0 ? 0 : hist[i] + 1;

      // Get the sorted histogram.
      int[] sortedHist = hist.clone();
      Arrays.sort(sortedHist);

      // Greedily calculate the answer.
      for (int i = 0; i < n; ++i)
        ans = Math.max(ans, sortedHist[i] * (n - i));
    }

    return ans;
  }
}
