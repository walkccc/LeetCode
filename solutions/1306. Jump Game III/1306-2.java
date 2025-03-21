class Solution {
  public boolean canReach(int[] arr, int start) {
    return canReach(arr, start, new boolean[arr.length]);
  }

  private boolean canReach(int[] arr, int node, boolean[] seen) {
    if (node < 0 || node >= arr.length)
      return false;
    if (seen[node])
      return false;
    if (arr[node] == 0)
      return true;
    seen[node] = true;
    return canReach(arr, node + arr[node], seen) || canReach(arr, node - arr[node], seen);
  }
}
