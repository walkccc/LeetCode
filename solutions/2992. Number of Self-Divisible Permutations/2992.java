class Solution {
  public int selfDivisiblePermutationCount(int n) {
    return dfs(1, /*used=*/0, n);
  }

  private int dfs(int num, int used, int n) {
    if (num > n)
      return 1;

    int count = 0;
    for (int i = 1; i <= n; i++)
      if (((used >> i) & 1) == 0 && (num % i == 0 || i % num == 0))
        count += dfs(num + 1, used | (1 << i), n);

    return count;
  }
}
