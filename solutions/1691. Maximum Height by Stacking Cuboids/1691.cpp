class Solution {
 public:
  int maxHeight(vector<vector<int>>& cuboids) {
    // for each cuboid, sort it so that c[0] <= c[1] <= c[2]
    for (vector<int>& c : cuboids)
      sort(begin(c), end(c));

    sort(begin(cuboids), end(cuboids));

    // dp[i] := max height w/ cuboids[i] in the bottom
    vector<int> dp(cuboids.size());

    for (int i = 0; i < cuboids.size(); ++i)
      dp[i] = cuboids[i][2];

    for (int i = 1; i < cuboids.size(); ++i)
      for (int j = 0; j < i; ++j)
        if (cuboids[j][0] <= cuboids[i][0] &&
            cuboids[j][1] <= cuboids[i][1] &&
            cuboids[j][2] <= cuboids[i][2])
          dp[i] = max(dp[i], dp[j] + cuboids[i][2]);

    return *max_element(begin(dp), end(dp));
  }
};
