class Solution {
  public int evalRPN(String[] tokens) {
    Stack<Integer> stack = new Stack<Integer>();

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
          final int b = stack.pop();
          final int a = stack.pop();
          stack.push(a / b);
          break;
        default:
          stack.push(Integer.parseInt(token));
      }

    return stack.peek();
  }
}
