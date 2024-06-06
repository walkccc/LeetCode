class Solution {
 public:
  int palindromePartition(string s, int k) {
    const int n = s.length();
    vector<vector<int>> mem(n + 1, vector<int>(k + 1, n));
    // cost[i][j] := the minimum cost to make s[i..j] palindrome
    vector<vector<int>> cost(n, vector<int>(n));

    for (int d = 1; d < n; ++d)
      for (int i = 0, j = d; j < n; ++i, ++j)
        cost[i][j] = (s[i] != s[j]) + cost[i + 1][j - 1];

    return palindromePartition(n, k, cost, mem);
  }

 private:
  // Returns the minimum cost to make k palindromes by s[0..i).
  int palindromePartition(int n, int k, const vector<vector<int>>& cost,
                          vector<vector<int>>& mem) {
    if (k == 1)
      return cost[0][n - 1];
    if (mem[n][k] < n)
      return mem[n][k];

    // Try all the possible partitions.
    for (int i = k - 1; i < n; ++i)
      mem[n][k] = min(
          mem[n][k], palindromePartition(i, k - 1, cost, mem) + cost[i][n - 1]);

    return mem[n][k];
  }
};
