class Solution {
  public int evalRPN(String[] tokens) {
    final Map<String, BinaryOperator<Long>> op = Map.of(
        "+", (a, b) -> a + b, "-", (a, b) -> a - b, "*", (a, b) -> a * b, "/", (a, b) -> a / b);
    Deque<Long> stack = new ArrayDeque<>();

    for (final String token : tokens)
      if (op.containsKey(token)) {
        final long b = stack.pop();
        final long a = stack.pop();
        stack.push(op.get(token).apply(a, b));
      } else {
        stack.push(Long.parseLong(token));
      }

    return stack.pop().intValue();
  }
}
