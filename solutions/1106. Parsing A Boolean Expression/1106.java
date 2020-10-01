class Solution {
  public boolean parseBoolExpr(String expression) {
    return dfs(expression, 0, expression.length() - 1);
  }

  private boolean dfs(final String expression, int s, int e) {
    if (s == e)
      return expression.charAt(s) == 't';

    List<Boolean> exps = new ArrayList<>();
    int layer = 0;
    int left = 0;
    char op = ' ';

    for (int i = s; i <= e; ++i) {
      char c = expression.charAt(i);
      if (layer == 0 && (c == '!' || c == '&' || c == '|'))
        op = c;
      else if (c == '(' && ++layer == 1)
        left = i + 1;
      else if (c == ')' && --layer == 0)
        exps.add(dfs(expression, left, i - 1));
      else if (c == ',' && layer == 1) {
        exps.add(dfs(expression, left, i - 1));
        left = i + 1;
      }
    }

    if (op == '&') {
      boolean ans = true;
      for (boolean exp : exps)
        ans &= exp;
      return ans;
    }

    if (op == '|') {
      boolean ans = false;
      for (boolean exp : exps)
        ans |= exp;
      return ans;
    }

    return !exps.get(0);
  }
}