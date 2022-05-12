class Solution {
  public int maxDistance(List<List<Integer>> arrays) {
    int ans = 0;
    int min = 10000;
    int max = -10000;

    for (List<Integer> A : arrays) {
      ans = Math.max(ans, Math.max(A.get(A.size() - 1) - min, max - A.get(0)));
      min = Math.min(min, A.get(0));
      max = Math.max(max, A.get(A.size() - 1));
    }

    return ans;
  }
}
