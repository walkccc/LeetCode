class Solution {
 public:
  int mergeStones(vector<int>& stones, int k) {
    const int n = stones.size();
    if ((n - 1) % (k - 1))
      return -1;

    vector<vector<int>> mem(n, vector<int>(n, kMax));
    vector<int> prefix(n + 1);

    partial_sum(stones.begin(), stones.end(), prefix.begin() + 1);
    const int cost = mergeStones(stones, 0, n - 1, k, prefix, mem);
    return cost == kMax ? -1 : cost;
  }

 private:
  static constexpr int kMax = 1'000'000'000;

  // Returns the minimum cost to merge stones[i..j].
  int mergeStones(const vector<int>& stones, int i, int j, int k,
                  const vector<int>& prefix, vector<vector<int>>& mem) {
    if (j - i + 1 < k)
      return 0;
    if (mem[i][j] != kMax)
      return mem[i][j];

    for (int m = i; m < j; m += k - 1)
      mem[i][j] =
          min(mem[i][j], mergeStones(stones, i, m, k, prefix, mem) +
                             mergeStones(stones, m + 1, j, k, prefix, mem));
    if ((j - i) % (k - 1) == 0)
      mem[i][j] += prefix[j + 1] - prefix[i];

    return mem[i][j];
  }
};
