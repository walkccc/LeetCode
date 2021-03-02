class Solution {
 public:
  int numDupDigitsAtMostN(int N) {
    int uniqueNumbers = 0;

    dfs(N, 0, 0, uniqueNumbers);

    return N - uniqueNumbers + 1;
  }

 private:
  void dfs(int N, int mask, long path, int& uniqueNumbers) {
    if (path > N)
      return;

    ++uniqueNumbers;

    for (int digit = 0; digit < 10; ++digit) {
      if (mask == 0 && digit == 0)
        continue;
      if (mask & (1 << digit))
        continue;
      dfs(N, mask | (1 << digit), path * 10 + digit, uniqueNumbers);
    }
  }
};
