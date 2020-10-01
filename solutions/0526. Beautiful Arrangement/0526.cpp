class Solution {
 public:
  int countArrangement(int N) {
    string filled(N + 1, 'x');  // positions are filled
    unordered_map<string, int> memo;

    function<int(int)> dfs = [&](int num) {
      if (num == N + 1) return 1;
      if (memo.count(filled)) return memo[filled];

      int count = 0;

      for (int i = 1; i <= N; ++i)
        if (filled[i] == 'x' && (num % i == 0 || i % num == 0)) {
          filled[i] = 'o';
          count += dfs(num + 1);
          filled[i] = 'x';
        }

      return memo[filled] = count;
    };

    return dfs(1);
  }
};