class Solution {
  public int[] numsSameConsecDiff(int n, int k) {
    if (n == 1)
      return new int[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    List<Integer> ans = new ArrayList<>();

    if (k == 0) {
      for (char c = '1'; c <= '9'; ++c) {
        final String s = String.valueOf(c).repeat(n);
        ans.add(Integer.parseInt(s));
      }
      return ans.stream().mapToInt(Integer::intValue).toArray();
    }

    for (int num = 1; num <= 9; ++num)
      dfs(n - 1, k, num, ans);

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  private void dfs(int n, int k, int num, List<Integer> ans) {
    if (n == 0) {
      ans.add(num);
      return;
    }

    final int lastDigit = num % 10;

    for (final int nextDigit : new int[] {lastDigit - k, lastDigit + k})
      if (0 <= nextDigit && nextDigit <= 9)
        dfs(n - 1, k, num * 10 + nextDigit, ans);
  }
}
