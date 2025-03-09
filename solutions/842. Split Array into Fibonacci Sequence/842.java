class Solution {
  public List<Integer> splitIntoFibonacci(String num) {
    List<Integer> ans = new ArrayList<>();
    dfs(num, 0, ans);
    return ans;
  }

  private boolean dfs(final String num, int s, List<Integer> ans) {
    if (s == num.length() && ans.size() >= 3)
      return true;

    for (int i = s; i < num.length(); ++i) {
      if (num.charAt(s) == '0' && i > s)
        break;
      final long val = Long.valueOf(num.substring(s, i + 1));
      if (val > Integer.MAX_VALUE)
        break;
      if (ans.size() >= 2 && val > ans.get(ans.size() - 2) + ans.get(ans.size() - 1))
        break;
      if (ans.size() <= 1 || val == ans.get(ans.size() - 2) + ans.get(ans.size() - 1)) {
        ans.add((int) val);
        if (dfs(num, i + 1, ans))
          return true;
        ans.remove(ans.size() - 1);
      }
    }

    return false;
  }
}
