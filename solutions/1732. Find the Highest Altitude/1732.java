class Solution {
  public int largestAltitude(int[] gain) {
    int ans = 0;
    int currAltitude = 0;
    for (final int g : gain) {
      currAltitude += g;
      ans = Math.max(ans, currAltitude);
    }
    return ans;
  }
}
