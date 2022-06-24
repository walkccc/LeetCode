class Solution {
  public boolean validMountainArray(int[] A) {
    if (A.length < 3)
      return false;

    int l = 0;
    int r = A.length - 1;

    while (l + 1 < A.length && A[l] < A[l + 1])
      ++l;
    while (r > 0 && A[r] < A[r - 1])
      --r;

    return l > 0 && r < A.length - 1 && l == r;
  }
}
