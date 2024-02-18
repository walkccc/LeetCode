class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    const int n = piles.size();
    vector<vector<int>> mem(n, vector<int>(n));
    vector<int> suffix = piles;  // suffix[i] := sum(piles[i..n))
    for (int i = n - 2; i >= 0; --i)
      suffix[i] += suffix[i + 1];
    return stoneGameII(suffix, 0, 1, mem);
  }

 private:
  // Returns the maximum number of stones Alice can get from piles[i..n) with M.
  int stoneGameII(const vector<int>& suffix, int i, int M,
                  vector<vector<int>>& mem) {
    if (i + 2 * M >= mem.size())
      return suffix[i];
    if (mem[i][M] > 0)
      return mem[i][M];

    int opponent = suffix[i];

    for (int X = 1; X <= 2 * M; ++X)
      opponent = min(opponent, stoneGameII(suffix, i + X, max(M, X), mem));

    return mem[i][M] = suffix[i] - opponent;
  }
};
