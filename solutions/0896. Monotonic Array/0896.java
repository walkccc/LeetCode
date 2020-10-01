class Solution {
  public boolean isMonotonic(int[] A) {
    boolean increasing = true;
    boolean decreasing = true;

    for (int i = 1; i < A.length; ++i) {
      increasing &= A[i - 1] <= A[i];
      decreasing &= A[i - 1] >= A[i];
    }

    return increasing || decreasing;
  }
}