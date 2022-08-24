class Solution {
  public int[] beautifulArray(int n) {
    int[] A = new int[n];
    for (int i = 0; i < n; ++i)
      A[i] = i + 1;
    divide(A, 0, n - 1, 1);
    return A;
  }

  private void divide(int[] A, int l, int r, int mask) {
    if (l >= r)
      return;
    final int m = partition(A, l, r, mask);
    divide(A, l, m, mask << 1);
    divide(A, m + 1, r, mask << 1);
  }

  private int partition(int[] A, int l, int r, int mask) {
    int nextSwapped = l;
    for (int i = l; i <= r; ++i)
      if ((A[i] & mask) > 0)
        swap(A, i, nextSwapped++);
    return nextSwapped - 1;
  }

  private void swap(int[] A, int i, int j) {
    final int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
}
