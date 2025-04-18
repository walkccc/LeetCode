class Solution {
  public int addRungs(int[] rungs, int dist) {
    int ans = 0;
    int prev = 0;

    for (final int rung : rungs) {
      ans += (rung - prev - 1) / dist;
      prev = rung;
    }

    return ans;
  }
}
