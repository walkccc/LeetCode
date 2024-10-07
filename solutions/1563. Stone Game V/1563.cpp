class Solution {
 public:
  int stoneGameV(vector<int>& stoneValue) {
    const int n = stoneValue.size();
    vector<vector<int>> mem(n, vector<int>(n, INT_MIN));
    vector<int> prefix(n + 1);
    partial_sum(stoneValue.begin(), stoneValue.end(), prefix.begin() + 1);
    return stoneGameV(stoneValue, 0, n - 1, prefix, mem);
  }

 private:
  // Returns the maximum score that Alice can obtain from stoneValue[i..j].
  int stoneGameV(const vector<int>& stoneValue, int i, int j,
                 const vector<int>& prefix, vector<vector<int>>& mem) {
    if (i == j)
      return 0;
    if (mem[i][j] > 0)
      return mem[i][j];

    // Try all the possible partitions.
    for (int p = i; p < j; ++p) {
      // sum(stoneValue[i..p])
      const int leftSum = prefix[p + 1] - prefix[i];
      const int throwRight =
          leftSum + stoneGameV(stoneValue, i, p, prefix, mem);
      // sum(stoneValue[p + 1..j])
      const int rightSum = prefix[j + 1] - prefix[p + 1];
      const int throwLeft =
          rightSum + stoneGameV(stoneValue, p + 1, j, prefix, mem);
      if (leftSum < rightSum)  // Bob throws the right row.
        mem[i][j] = max(mem[i][j], throwRight);
      else if (leftSum > rightSum)  // Bob throws the left row.
        mem[i][j] = max(mem[i][j], throwLeft);
      else  // Alice decides which row to throw.
        mem[i][j] = max({mem[i][j], throwLeft, throwRight});
    }

    return mem[i][j];
  }
};
