class Solution {
  public List<Integer> countSteppingNumbers(int low, int high) {
    List<Integer> ans = new ArrayList<>();
    if (low == 0)
      ans.add(0);

    for (long i = 1; i <= 9; ++i)
      dfs(i, low, high, ans);

    Collections.sort(ans);
    return ans;
  }

  private void dfs(long curr, int low, int high, List<Integer> ans) {
    if (curr > high)
      return;
    if (curr >= low)
      ans.add((int) curr);

    final long lastDigit = curr % 10;
    if (lastDigit > 0)
      dfs(curr * 10 + lastDigit - 1, low, high, ans);
    if (lastDigit < 9)
      dfs(curr * 10 + lastDigit + 1, low, high, ans);
  }
}
