class Solution {
 public:
  int minimumFinishTime(vector<vector<int>>& tires, int changeTime,
                        int numLaps) {
    // dp[i] := the minimum time of the first i laps
    vector<int> dp(numLaps + 1, INT_MAX);

    for (const vector<int>& t : tires)
      for (int seconds = t[0], secondsSum = t[0], lapCount = 1;
           seconds < t[0] + changeTime && lapCount < dp.size();
           seconds *= t[1], ++lapCount, secondsSum += seconds)
        dp[lapCount] = min(secondsSum, dp[lapCount]);

    for (int i = 2; i <= numLaps; ++i)
      for (int j = 1; j * 2 <= i; ++j)
        dp[i] = min(dp[i], dp[j] + dp[i - j] + changeTime);

    return dp[numLaps];
  }
};
