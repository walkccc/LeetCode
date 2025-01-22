class Solution {
 public:
  int minimumFinishTime(vector<vector<int>>& tires, int changeTime,
                        int numLaps) {
    // singleTire[i] := the minimum time to finish i laps without changing tire
    vector<int> singleTire(numLaps + 1, INT_MAX / 2);
    // dp[i] := the minimum time to finish i laps
    vector<int> dp(numLaps + 1, INT_MAX / 2);

    for (int i = 0; i < tires.size(); ++i) {
      const int f = tires[i][0];
      const int r = tires[i][1];
      int sumSecs = 0;
      int rPower = 1;
      for (int j = 1; j <= numLaps; ++j) {
        // the time to use the same tire for the next lap >=
        // the time to change a new tire + f
        if ((long)f * rPower >= changeTime + f)
          break;
        sumSecs += f * rPower;
        rPower *= r;
        singleTire[j] = min(singleTire[j], sumSecs);
      }
    }

    dp[0] = 0;
    for (int i = 1; i <= numLaps; ++i)
      for (int j = 1; j <= i; ++j)
        dp[i] = min(dp[i], dp[i - j] + changeTime + singleTire[j]);

    return dp[numLaps] - changeTime;
  }
};
