class Solution {
  public int maxScoreSightseeingPair(int[] A) {
    int ans = 0;
    int bestPrev = 0;

    for (int a : A) {
      ans = Math.max(ans, a + bestPrev);
      bestPrev = Math.max(bestPrev, a) - 1;
    }

    return ans;
  }
}
