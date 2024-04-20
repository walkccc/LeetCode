class Solution {
 public:
  int strangePrinter(string s) {
    const int n = s.length();
    vector<vector<int>> mem(n, vector<int>(n));
    return strangePrinter(s, 0, n - 1, mem);
  }

 private:
  // Returns the minimum number of turns to print s[i..j].
  int strangePrinter(const string& s, int i, int j, vector<vector<int>>& mem) {
    if (i > j)
      return 0;
    if (mem[i][j] > 0)
      return mem[i][j];

    // Print s[i].
    mem[i][j] = strangePrinter(s, i + 1, j, mem) + 1;

    for (int k = i + 1; k <= j; ++k)
      if (s[k] == s[i])
        mem[i][j] = min(mem[i][j], strangePrinter(s, i, k - 1, mem) +
                                       strangePrinter(s, k + 1, j, mem));

    return mem[i][j];
  }
};
