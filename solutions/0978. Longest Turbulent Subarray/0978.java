class Solution {
  public int maxTurbulenceSize(int[] A) {
    int ans = 1;
    int increasing = 1;
    int decreasing = 1;

    for (int i = 1; i < A.length; ++i) {
      if (A[i] > A[i - 1]) {
        increasing = decreasing + 1;
        decreasing = 1;
      } else if (A[i] < A[i - 1]) {
        decreasing = increasing + 1;
        increasing = 1;
      } else {
        increasing = 1;
        decreasing = 1;
      }
      ans = Math.max(ans, Math.max(increasing, decreasing));
    }

    return ans;
  }
}
