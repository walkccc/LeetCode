class Solution {
 public:
  int minimumFinishTime(vector<vector<int>>& tires, int changeTime,
                        int numLaps) {
    // singleTire[i] := min time to finish i laps w/o changing tire
    vector<int> singleTire(numLaps + 1, INT_MAX / 2);
    // dp[i] := min time to finish i laps
    vector<int> dp(numLaps + 1, INT_MAX / 2);

    for (int i = 0; i < tires.size(); ++i) {
      const int f = tires[i][0];
      const int r = tires[i][1];
      int sumSecs = 0;
      int rPower = 1;
      for (int j = 1; j <= numLaps; ++j) {
        // time to use the same tire for next lap >=
        // time to change a new tire + f
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
