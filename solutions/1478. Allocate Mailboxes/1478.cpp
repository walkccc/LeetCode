class Solution {
 public:
  int minDistance(vector<int>& houses, int k) {
    const int n = houses.size();
    vector<vector<int>> mem(n, vector<int>(k + 1, INT_MAX));
    // cost[i][j] := the minimum cost to allocate mailboxes between houses[i]
    // and houses[j]
    vector<vector<int>> cost(n, vector<int>(n));

    ranges::sort(houses);

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        const int median = houses[(i + j) / 2];
        for (int x = i; x <= j; ++x)
          cost[i][j] += abs(houses[x] - median);
      }

    return minDistance(houses, 0, k, cost, mem);
  }

 private:
  static constexpr int kMax = 1'000'000;

  // Returns the minimum distance to allocate k mailboxes for houses[i..n).
  int minDistance(const vector<int>& houses, int i, int k,
                  const vector<vector<int>>& cost, vector<vector<int>>& mem) {
    if (i == houses.size() && k == 0)
      return 0;
    if (i == houses.size() || k == 0)
      return kMax;
    if (mem[i][k] != INT_MAX)
      return mem[i][k];

    for (int j = i; j < houses.size(); ++j)
      mem[i][k] = min(
          mem[i][k], cost[i][j] + minDistance(houses, j + 1, k - 1, cost, mem));

    return mem[i][k];
  }
};
