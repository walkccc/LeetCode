class Solution {
 public:
  int countArrangement(int n) {
    return dfs(n, 1, string(n + 1, 'x'), {});
  }

 private:
  int dfs(int n, int num, string&& filled, unordered_map<string, int>&& memo) {
    if (num == n + 1)
      return 1;
    if (const auto it = memo.find(filled); it != memo.cend())
      return it->second;

    int count = 0;

    for (int i = 1; i <= n; ++i)
      if (filled[i] == 'x' && (num % i == 0 || i % num == 0)) {
        filled[i] = 'o';
        count += dfs(n, num + 1, move(filled), move(memo));
        filled[i] = 'x';
      }

    return memo[filled] = count;
  }
};
