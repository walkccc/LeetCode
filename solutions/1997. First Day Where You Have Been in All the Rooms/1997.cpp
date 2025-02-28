class Solution {
 public:
  int firstDayBeenInAllRooms(vector<int>& nextVisit) {
    constexpr int kMod = 1'000'000'007;
    const int n = nextVisit.size();
    // dp[i] := the number of days to visit room i for the first time
    vector<int> dp(n);

    // Whenever we visit i, visit times of room[0..i - 1] are all even.
    // Therefore, the rooms before i can be seen as reset and we can safely
    // reuse dp[0..i - 1] as first-time visit to get second-time visit.
    for (int i = 1; i < n; ++i)
      // The total days to visit room[i] is the sum of
      //   * dp[i - 1]: 1st-time visit room[i - 1]
      //   * 1: visit room[nextVisit[i - 1]]
      //   * dp[i - 1] - dp[nextVisit[i - 1]]: 2-time visit room[i - 1]
      //   * 1: visit room[i]
      dp[i] = (2L * dp[i - 1] - dp[nextVisit[i - 1]] + 2 + kMod) % kMod;

    return dp.back();
  }
};
