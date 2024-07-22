class Solution {
 public:
  int mergeStones(vector<int>& stones, int K) {
    const int n = stones.size();
    vector<vector<vector<int>>> mem(
        n, vector<vector<int>>(n, vector<int>(K + 1, kMax)));
    vector<int> prefix(n + 1);
    partial_sum(stones.begin(), stones.end(), prefix.begin() + 1);
    const int cost = mergeStones(stones, 0, n - 1, 1, K, prefix, mem);
    return cost == kMax ? -1 : cost;
  }

 private:
  static constexpr int kMax = 1'000'000'000;

  // Returns the minimum cost to merge stones[i..j] into k piles.
  int mergeStones(const vector<int>& stones, int i, int j, int k, int K,
                  const vector<int>& prefix, vector<vector<vector<int>>>& mem) {
    if ((j - i + 1 - k) % (K - 1))
      return kMax;
    if (i == j)
      return k == 1 ? 0 : kMax;
    if (mem[i][j][k] != kMax)
      return mem[i][j][k];
    if (k == 1)
      return mem[i][j][k] = mergeStones(stones, i, j, K, K, prefix, mem) +
                            prefix[j + 1] - prefix[i];

    for (int m = i; m < j; m += K - 1)
      mem[i][j][k] =
          min(mem[i][j][k],
              mergeStones(stones, i, m, 1, K, prefix, mem) +
                  mergeStones(stones, m + 1, j, k - 1, K, prefix, mem));

    return mem[i][j][k];
  }
};
