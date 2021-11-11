class Solution {
 public:
  int countArrangement(int N) {
    string filled(N + 1, 'x');
    unordered_map<string, int> memo;

    return dfs(N, 1, filled, memo);
  }

 private:
  int dfs(int N, int num, string& filled, unordered_map<string, int>& memo) {
    if (num == N + 1)
      return 1;
    if (memo.count(filled))
      return memo[filled];

    int count = 0;

    for (int i = 1; i <= N; ++i)
      if (filled[i] == 'x' && (num % i == 0 || i % num == 0)) {
        filled[i] = 'o';
        count += dfs(N, num + 1, filled, memo);
        filled[i] = 'x';
      }

    return memo[filled] = count;
  }
};
