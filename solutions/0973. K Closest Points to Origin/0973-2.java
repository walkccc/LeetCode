class Solution {
  public int[][] kClosest(int[][] points, int k) {
    quickSelect(points, 0, points.length - 1, k);
    return Arrays.copyOfRange(points, 0, k);
  }

  private void quickSelect(int[][] points, int l, int r, int k) {
    final int[] pivot = points[r];

    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (squareDist(points[i]) <= squareDist(pivot))
        swap(points, nextSwapped++, i);
    swap(points, nextSwapped, r);

    final int count = nextSwapped - l + 1; // the number of points <= pivot
    if (count == k)
      return;
    if (count > k)
      quickSelect(points, l, nextSwapped - 1, k);
    else
      quickSelect(points, nextSwapped + 1, r, k - count);
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
