class Solution {
  public int minCost(String colors, int[] neededTime) {
    int ans = 0;
    int maxNeededTime = neededTime[0];

    for (int i = 1; i < colors.length(); ++i)
      if (colors.charAt(i) == colors.charAt(i - 1)) {
        ans += Math.min(maxNeededTime, neededTime[i]);
        // For each continuous group, Bob needs to remove every balloon except the one with the max
        // `neededTime`. So, he should hold the balloon with the highest `neededTime` in his hand.
        maxNeededTime = Math.max(maxNeededTime, neededTime[i]);
      } else {
        // If the current balloon is different from the previous one, discard the balloon from the
        // previous group and hold the new one in hand.
        maxNeededTime = neededTime[i];
      }

    return ans;
  }
}
