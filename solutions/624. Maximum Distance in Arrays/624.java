class Solution {
  public int maxDistance(List<List<Integer>> arrays) {
    int ans = 0;
    int mn = 10000;
    int mx = -10000;

    for (List<Integer> A : arrays) {
      ans = Math.max(ans, Math.max(A.get(A.size() - 1) - mn, mx - A.get(0)));
      mn = Math.min(mn, A.get(0));
      mx = Math.max(mx, A.get(A.size() - 1));
    }

    return ans;
  }
}
