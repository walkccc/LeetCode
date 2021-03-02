class Solution {
  public List<Integer> splitIntoFibonacci(String S) {
    List<Integer> ans = new ArrayList<>();

    dfs(S, 0, ans);

    return ans;
  }

  private boolean dfs(final String S, int s, List<Integer> ans) {
    if (s == S.length() && ans.size() >= 3)
      return true;

    for (int i = s; i < S.length(); ++i) {
      if (S.charAt(s) == '0' && i > s)
        break;
      final long num = Long.valueOf(S.substring(s, i + 1));
      if (num > Integer.MAX_VALUE)
        break;
      if (ans.size() >= 2 && num > ans.get(ans.size() - 2) + ans.get(ans.size() - 1))
        break;
      if (ans.size() <= 1 || num == ans.get(ans.size() - 2) + ans.get(ans.size() - 1)) {
        ans.add((int) num);
        if (dfs(S, i + 1, ans))
          return true;
        ans.remove(ans.size() - 1);
      }
    }

    return false;
  }
}
