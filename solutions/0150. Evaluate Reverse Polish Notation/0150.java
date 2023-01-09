class Solution {
  public int evalRPN(String[] tokens) {
    Deque<Long> stack = new ArrayDeque<>();

    for (final String token : tokens)
      switch (token) {
        case "+":
          stack.push(stack.pop() + stack.pop());
          break;
        case "-":
          stack.push(-stack.pop() + stack.pop());
          break;
        case "*":
          stack.push(stack.pop() * stack.pop());
          break;
        case "/":
          final long b = stack.pop();
          final long a = stack.pop();
          stack.push(a / b);
          break;
        default:
          stack.push(Long.parseLong(token));
      }

    return stack.peek().intValue();
  }
}
