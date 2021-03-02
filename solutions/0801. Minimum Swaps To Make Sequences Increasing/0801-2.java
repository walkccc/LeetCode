class Solution {
  public int minSwap(int[] A, int[] B) {
    int keepAt = 0;
    int swapAt = 1;
    int prevKeepAt = 0;
    int prevSwapAt = 1;

    for (int i = 1; i < A.length; ++i) {
      keepAt = Integer.MAX_VALUE;
      swapAt = Integer.MAX_VALUE;
      if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
        keepAt = prevKeepAt;
        swapAt = prevSwapAt + 1;
      }
      if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
        keepAt = Math.min(keepAt, prevSwapAt);
        swapAt = Math.min(swapAt, prevKeepAt + 1);
      }
      prevKeepAt = keepAt;
      prevSwapAt = swapAt;
    }

    return Math.min(keepAt, swapAt);
  }
}
