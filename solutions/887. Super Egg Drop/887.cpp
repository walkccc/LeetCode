class Solution {
 public:
  int superEggDrop(int k, int n) {
    vector<vector<int>> mem(k + 1, vector<int>(n + 1, INT_MAX));
    return drop(k, n, mem);
  }

 private:
  // Returns the minimum number of moves to know f with k eggs and n floors.
  int drop(int k, int n, vector<vector<int>>& mem) {
    if (k == 0)  // no eggs -> done
      return 0;
    if (k == 1)  // one egg -> drop from 1-th floor to n-th floor
      return n;
    if (n == 0)  // no floor -> done
      return 0;
    if (n == 1)  // one floor -> drop from that floor
      return 1;
    if (mem[k][n] != INT_MAX)
      return mem[k][n];

    for (int i = 1; i <= n; ++i) {
      const int broken = drop(k - 1, i - 1, mem);
      const int unbroken = drop(k, n - i, mem);
      mem[k][n] = min(mem[k][n], 1 + max(broken, unbroken));
    }

    return mem[k][n];
  }
};
