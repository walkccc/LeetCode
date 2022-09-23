class Solution {
  public int minimumFinishTime(int[][] tires, int changeTime, int numLaps) {
    // singleTire[i] := min time to finish i laps w/o changing tire
    int[] singleTire = new int[numLaps + 1];
    // dp[i] := min time to finish i laps
    int[] dp = new int[numLaps + 1];

    Arrays.fill(singleTire, Integer.MAX_VALUE / 2);
    Arrays.fill(dp, Integer.MAX_VALUE / 2);

    for (int i = 0; i < tires.length; ++i) {
      final int f = tires[i][0];
      final int r = tires[i][1];
      int sumSecs = 0;
      int rPower = 1;
      for (int j = 1; j <= numLaps; ++j) {
        // time to use the same tire for next lap >=
        // time to change a new tire + f
        if ((long) f * rPower >= changeTime + f)
          break;
        sumSecs += f * rPower;
        rPower *= r;
        singleTire[j] = Math.min(singleTire[j], sumSecs);
      }
    }

    dp[0] = 0;
    for (int i = 1; i <= numLaps; ++i)
      for (int j = 1; j <= i; ++j)
        dp[i] = Math.min(dp[i], dp[i - j] + changeTime + singleTire[j]);

    return dp[numLaps] - changeTime;
  }
}
