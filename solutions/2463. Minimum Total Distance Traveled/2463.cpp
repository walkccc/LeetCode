class Solution {
 public:
  long long minimumTotalDistance(vector<int>& robot,
                                 vector<vector<int>>& factory) {
    ranges::sort(robot);
    ranges::sort(factory);

    // dp[i][j][k] := the minimum distance to fix robot[i..n) with
    // factory[j..n), where factory[j] already fixed k robots
    dp.resize(robot.size(),
              vector<vector<long long>>(factory.size(),
                                        vector<long long>(robot.size())));
    return minimumTotalDistance(robot, factory, 0, 0, 0);
  }

 private:
  vector<vector<vector<long long>>> dp;

  long long minimumTotalDistance(const vector<int>& robot,
                                 const vector<vector<int>>& factory, int i,
                                 int j, int k) {
    if (i == robot.size())
      return 0;
    if (j == factory.size())
      return LLONG_MAX;
    if (dp[i][j][k] > 0)
      return dp[i][j][k];
    const long long skipFactory =
        minimumTotalDistance(robot, factory, i, j + 1, 0);
    const int position = factory[j][0];
    const int limit = factory[j][1];
    const long long useFactory =
        limit > k ? minimumTotalDistance(robot, factory, i + 1, j, k + 1) +
                        abs(robot[i] - position)
                  : LLONG_MAX / 2;
    return dp[i][j][k] = min(skipFactory, useFactory);
  }
};
