class Solution {
 public:
  long long maximumTotalDamage(vector<int>& power) {
    unordered_map<int, int> count;

    for (const int damage : power)
      ++count[damage];

    const vector<int> uniqueDamages = getSortedUniqueDamages(count);
    const int n = uniqueDamages.size();
    // dp[i][k] := the maximum damage using uniqueDamages[0..i], where k
    // indicates if the i-th damage is used
    vector<vector<long>> dp(n, vector<long>(2));

    for (int i = 0; i < n; ++i) {
      const long damage = uniqueDamages[i];
      if (i == 0) {
        dp[0][0] = 0;
        dp[0][1] = damage * count[damage];
        continue;
      }
      dp[i][0] = ranges::max(dp[i - 1]);
      dp[i][1] = damage * count[damage];
      if (i >= 1 && uniqueDamages[i - 1] != damage - 1 &&
          uniqueDamages[i - 1] != damage - 2) {
        dp[i][1] += max(dp[i - 1][0], dp[i - 1][1]);
      } else if (i >= 2 && uniqueDamages[i - 2] != damage - 2) {
        dp[i][1] += max(dp[i - 2][0], dp[i - 2][1]);
      } else if (i >= 3) {
        dp[i][1] += max(dp[i - 3][0], dp[i - 3][1]);
      }
    }

    return ranges::max(dp.back());
  }

 private:
  vector<int> getSortedUniqueDamages(const unordered_map<int, int>& count) {
    vector<int> uniqueDamages;
    for (const auto& [damage, _] : count)
      uniqueDamages.push_back(damage);
    ranges::sort(uniqueDamages);
    return uniqueDamages;
  }
};
