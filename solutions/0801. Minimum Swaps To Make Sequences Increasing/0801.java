class Solution {
  public int minSwap(int[] A, int[] B) {
    final int n = A.length;

    int[] keepAt = new int[n];
    int[] swapAt = new int[n];
    Arrays.fill(keepAt, Integer.MAX_VALUE);
    Arrays.fill(swapAt, Integer.MAX_VALUE);
    keepAt[0] = 0;
    swapAt[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
        keepAt[i] = keepAt[i - 1];
        swapAt[i] = swapAt[i - 1] + 1;
      }
      if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
        keepAt[i] = Math.min(keepAt[i], swapAt[i - 1]);
        swapAt[i] = Math.min(swapAt[i], keepAt[i - 1] + 1);
      }
    }

    return Math.min(keepAt[n - 1], swapAt[n - 1]);
  }
}
