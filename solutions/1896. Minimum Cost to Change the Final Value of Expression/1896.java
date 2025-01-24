class Solution {
  public int minOperationsToFlip(String expression) {
    // [(the expression, the cost to toggle the expression)]
    Deque<Pair<Character, Integer>> stack = new ArrayDeque<>();
    Pair<Character, Integer> lastPair = null;

    for (final char e : expression.toCharArray()) {
      if (e == '(' || e == '&' || e == '|') {
        // These aren't expressions, so the cost is meaningless.
        stack.push(new Pair<>(e, 0));
        continue;
      }
      if (e == ')') {
        lastPair = stack.pop();
        stack.pop(); // Pop '('.
      } else {       // e == '0' || e == '1'
        // Store the '0' or '1'. The cost to change their values is just 1,
        // whether it's changing '0' to '1' or '1' to '0'.
        lastPair = new Pair<>(e, 1);
      }
      if (!stack.isEmpty() && (stack.peek().getKey() == '&' || stack.peek().getKey() == '|')) {
        final char op = stack.pop().getKey();
        final char a = stack.peek().getKey();
        final int costA = stack.pop().getValue();
        final char b = lastPair.getKey();
        final int costB = lastPair.getValue();
        // Determine the cost to toggle op(a, b).
        if (op == '&') {
          if (a == '0' && b == '0')
            // Change '&' to '|' and a|b to '1'.
            lastPair = new Pair<>('0', 1 + Math.min(costA, costB));
          else if (a == '0' && b == '1')
            // Change '&' to '|'.
            lastPair = new Pair<>('0', 1);
          else if (a == '1' && b == '0')
            // Change '&' to '|'.
            lastPair = new Pair<>('0', 1);
          else // a == '1' and b == '1'
            // Change a|b to '0'.
            lastPair = new Pair<>('1', Math.min(costA, costB));
        } else { // op == '|'
          if (a == '0' && b == '0')
            // Change a|b to '1'.
            lastPair = new Pair<>('0', Math.min(costA, costB));
          else if (a == '0' && b == '1')
            // Change '|' to '&'.
            lastPair = new Pair<>('1', 1);
          else if (a == '1' && b == '0')
            // Change '|' to '&'.
            lastPair = new Pair<>('1', 1);
          else // a == '1' and b == '1'
            // Change '|' to '&' and a|b to '0'.
            lastPair = new Pair<>('1', 1 + Math.min(costA, costB));
        }
      }
      stack.push(lastPair);
    }

    return stack.peek().getValue();
  }
}
