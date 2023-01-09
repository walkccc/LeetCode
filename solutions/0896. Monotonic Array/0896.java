class Solution {
  public boolean isMonotonic(int[] A) {
    boolean increasing = true;
    boolean decreasing = true;

    for (int i = 1; i < A.length; ++i) {
      increasing &= A[i] >= A[i - 1];
      decreasing &= A[i] <= A[i - 1];
    }

    return increasing || decreasing;
  }
}
