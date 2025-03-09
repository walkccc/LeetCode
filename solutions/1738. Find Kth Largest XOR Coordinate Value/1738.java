class Solution {
  public int kthLargestValue(int[][] matrix, int k) {
    final int m = matrix.length;
    final int n = matrix[0].length;
    int[][] xors = new int[m + 1][n + 1];
    Queue<Integer> minHeap = new PriorityQueue<>();

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        xors[i][j] = xors[i - 1][j] ^ xors[i][j - 1] ^ xors[i - 1][j - 1] ^ matrix[i - 1][j - 1];
        minHeap.offer(xors[i][j]);
        if (minHeap.size() > k)
          minHeap.poll();
      }

    return minHeap.peek();
  }
}
