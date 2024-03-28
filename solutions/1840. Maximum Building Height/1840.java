class Solution {
  public int maxBuilding(int n, int[][] restrictions) {
    final int k = restrictions.length;
    int[][] A = new int[k + 2][2];
    System.arraycopy(restrictions, 0, A, 0, k);
    A[k] = new int[] {1, 0};
    A[k + 1] = new int[] {n, n - 1};

    Arrays.sort(A, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);

    for (int i = 1; i < A.length; ++i) {
      final int dist = A[i][0] - A[i - 1][0];
      A[i][1] = Math.min(A[i][1], A[i - 1][1] + dist);
    }

    for (int i = A.length - 2; i >= 0; --i) {
      final int dist = A[i + 1][0] - A[i][0];
      A[i][1] = Math.min(A[i][1], A[i + 1][1] + dist);
    }

    int ans = 0;

    for (int i = 1; i < A.length; ++i) {
      final int l = A[i - 1][0];
      final int r = A[i][0];
      final int hL = A[i - 1][1];
      final int hR = A[i][1];
      ans = Math.max(ans, Math.max(hL, hR) + (r - l - Math.abs(hL - hR)) / 2);
    }

    return ans;
  }
}
