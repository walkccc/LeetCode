class Solution {
  public int countTestedDevices(int[] batteryPercentages) {
    int ans = 0;

    for (final int batteryPercentage : batteryPercentages)
      if (batteryPercentage - ans > 0)
        ++ans;

    return ans;
  }
}
