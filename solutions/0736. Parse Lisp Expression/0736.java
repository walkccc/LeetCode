class Solution {
  public int evaluate(String expression) {
    return evaluate(expression, new HashMap<>());
  }

  private int evaluate(final String e, Map<String, Integer> prevScope) {
    if (Character.isDigit(e.charAt(0)) || e.charAt(0) == '-')
      return Integer.parseInt(e);
    if (prevScope.containsKey(e))
      return prevScope.get(e);

    Map<String, Integer> scope = new HashMap<>();
    scope.putAll(prevScope);
    String nextExpression = e.substring(e.indexOf(' ') + 1, e.length() - 1);
    List<String> tokens = parse(nextExpression);

    if (e.startsWith("(a"))
      return evaluate(tokens.get(0), scope) + evaluate(tokens.get(1), scope);
    if (e.startsWith("(m"))
      return evaluate(tokens.get(0), scope) * evaluate(tokens.get(1), scope);

    for (int i = 0; i < tokens.size() - 2; i += 2) // let
      scope.put(tokens.get(i), evaluate(tokens.get(i + 1), scope));

    return evaluate(tokens.get(tokens.size() - 1), scope);
  }

  private List<String> parse(final String s) {
    List<String> tokens = new ArrayList<>();
    StringBuilder sb = new StringBuilder();
    int parenthesis = 0;

    for (char c : s.toCharArray()) {
      if (c == '(')
        ++parenthesis;
      else if (c == ')')
        --parenthesis;
      if (parenthesis == 0 && c == ' ') {
        tokens.add(new String(sb));
        sb = new StringBuilder();
      } else
        sb.append(c);
    }

    if (sb.length() > 0)
      tokens.add(new String(sb));
    return tokens;
  }
}