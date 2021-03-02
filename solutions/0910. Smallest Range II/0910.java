class Solution {
  public int smallestRangeII(int[] A, int K) {
    Arrays.sort(A);

    int ans = A[A.length - 1] - A[0];
    int left = A[0] + K;
    int right = A[A.length - 1] - K;

    for (int i = 0; i + 1 < A.length; ++i) {
      int min = Math.min(left, A[i + 1] - K);
      int max = Math.max(right, A[i] + K);
      ans = Math.min(ans, max - min);
    }

    return ans;
  }
}
