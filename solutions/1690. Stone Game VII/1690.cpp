class Solution {
 public:
  int stoneGameVII(vector<int>& stones) {
    const int n = stones.size();
    vector<vector<int>> mem(n, vector<int>(n));
    vector<int> prefix(n + 1);
    partial_sum(stones.begin(), stones.end(), prefix.begin() + 1);
    return stoneGameVII(stones, 0, n - 1, prefix, mem);
  }

 private:
  // Returns the maximum score you can get more than your opponent in
  // stones[i..j].
  int stoneGameVII(const vector<int>& stones, int i, int j,
                   const vector<int>& prefix, vector<vector<int>>& mem) {
    if (i == j)
      return 0;
    if (mem[i][j] > 0)
      return mem[i][j];
    // Remove stones[i] to get sum(stones[i + 1..j]).
    const int removeLeft = prefix[j + 1] - prefix[i + 1] -
                           stoneGameVII(stones, i + 1, j, prefix, mem);
    // Remove stones[j] to get sum(stones[i..j - 1]).
    const int removeRight = prefix[j] - prefix[i] -  //
                            stoneGameVII(stones, i, j - 1, prefix, mem);
    return mem[i][j] = max(removeLeft, removeRight);
  }
};
