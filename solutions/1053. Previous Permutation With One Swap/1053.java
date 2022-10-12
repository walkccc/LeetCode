class Solution {
  public int[] prevPermOpt1(int[] A) {
    final int n = A.length;
    int l = n - 2;
    int r = n - 1;

    while (l >= 0 && A[l] <= A[l + 1])
      l--;
    if (l < 0)
      return A;
    while (A[r] >= A[l] || A[r] == A[r - 1])
      r--;
    swap(A, l, r);

    return A;
  }

  private void swap(int[] A, int l, int r) {
    int temp = A[l];
    A[l] = A[r];
    A[r] = temp;
  }
}
