class Solution {
  public boolean canReach(int[] arr, int start) {
    return canReach(arr, start, new boolean[arr.length]);
  }

  private boolean canReach(int[] A, int node, boolean[] seen) {
    if (node < 0 || node >= A.length)
      return false;
    if (seen[node])
      return false;
    if (A[node] == 0)
      return true;

    seen[node] = true;
    return canReach(A, node + A[node], seen) || canReach(A, node - A[node], seen);
  }
}
