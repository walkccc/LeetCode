class Solution {
 public:
  int countArrangement(int N) {
    return dfs(N, 1, string(N + 1, 'x'), {});
  }

 private:
  int dfs(int N, int num, string&& filled, unordered_map<string, int>&& memo) {
    if (num == N + 1)
      return 1;
    if (memo.count(filled))
      return memo[filled];

    int count = 0;

    for (int i = 1; i <= N; ++i)
      if (filled[i] == 'x' && (num % i == 0 || i % num == 0)) {
        filled[i] = 'o';
        count += dfs(N, num + 1, move(filled), move(memo));
        filled[i] = 'x';
      }

    return memo[filled] = count;
  }
};
