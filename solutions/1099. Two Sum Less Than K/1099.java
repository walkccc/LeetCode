class Solution {
  public int twoSumLessThanK(int[] A, int K) {
    if (A.length < 2)
      return -1;

    int ans = -1; // note the constraint that A[i] > 0
    int l = 0;
    int r = A.length - 1;

    Arrays.sort(A);

    while (l < r)
      if (A[l] + A[r] < K) {
        ans = Math.max(ans, A[l] + A[r]);
        ++l;
      } else {
        --r;
      }

    return ans;
  }
}
