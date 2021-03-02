class Solution {
  public boolean canWin(String s) {
    if (memo.containsKey(s))
      memo.get(s);

    // if any of s.substring(i, i + 2) == "++" and
    // your friend can't win after changing s.substring(i, i + 2) to "--" (or "-"),
    // then you can win
    for (int i = 0; i + 1 < s.length(); ++i)
      if (s.charAt(i) == '+' && s.charAt(i + 1) == '+'
          && !canWin(s.substring(0, i) + "-" + s.substring(i + 2))) {
        memo.put(s, true);
        return true;
      }

    memo.put(s, false);
    return false;
  }

  private Map<String, Boolean> memo = new HashMap<>();
}
