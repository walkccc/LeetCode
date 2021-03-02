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

    final int spaceIndex = e.indexOf(' ');
    final String nextExpression = e.substring(spaceIndex + 1, e.length() - 1); // -2: "()"
    List<String> tokens = split(nextExpression);

    if (e.startsWith("(m")) // mult
      return evaluate(tokens.get(0), scope) * evaluate(tokens.get(1), scope);
    if (e.startsWith("(a")) // add
      return evaluate(tokens.get(0), scope) + evaluate(tokens.get(1), scope);

    // let
    for (int i = 0; i < tokens.size() - 2; i += 2)
      scope.put(tokens.get(i), evaluate(tokens.get(i + 1), scope));
    return evaluate(tokens.get(tokens.size() - 1), scope);
  }

  private List<String> split(final String s) {
    List<String> tokens = new ArrayList<>();
    StringBuilder sb = new StringBuilder();
    int parenthesis = 0;

    for (char c : s.toCharArray()) {
      if (c == '(')
        ++parenthesis;
      else if (c == ')')
        --parenthesis;
      if (parenthesis == 0 && c == ' ') {
        tokens.add(sb.toString());
        sb.setLength(0);
      } else {
        sb.append(c);
      }
    }

    if (sb.length() > 0)
      tokens.add(sb.toString());
    return tokens;
  }
}
