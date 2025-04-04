class Solution {
  public int[][] diagonalSort(int[][] mat) {
    final int m = mat.length;
    final int n = mat[0].length;

    Map<Integer, Queue<Integer>> count = new HashMap<>();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        count.computeIfAbsent(i - j, k -> new PriorityQueue<>()).add(mat[i][j]);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        mat[i][j] = count.get(i - j).poll();

    return mat;
  }
}
