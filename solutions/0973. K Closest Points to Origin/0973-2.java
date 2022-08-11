class Solution {
  public int[][] kClosest(int[][] points, int K) {
    quickSelect(points, 0, points.length - 1, K);
    return Arrays.copyOfRange(points, 0, K);
  }

  private void quickSelect(int[][] points, int l, int r, int K) {
    final int[] pivot = points[r];

    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (squareDist(points[i]) <= squareDist(pivot))
        swap(points, nextSwapped++, i);
    swap(points, nextSwapped, r);

    final int count = nextSwapped - l + 1; // # of points <= pivot
    if (count == K)
      return;
    if (count > K)
      quickSelect(points, l, nextSwapped - 1, K);
    else
      quickSelect(points, nextSwapped + 1, r, K - count);
  }

  private int squareDist(int[] p) {
    return p[0] * p[0] + p[1] * p[1];
  }

  private void swap(int[][] points, int i, int j) {
    final int[] temp = points[i];
    points[i] = points[j];
    points[j] = temp;
  }
}
