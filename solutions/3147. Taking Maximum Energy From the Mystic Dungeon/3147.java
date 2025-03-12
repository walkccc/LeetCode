class Solution {
  public int maximumEnergy(int[] energy, int k) {
    int[] dp = energy.clone();
    for (int i = energy.length - 1 - k; i >= 0; --i)
      dp[i] += dp[i + k];
    return Arrays.stream(dp).max().getAsInt();
  }
}
