class Solution {
  public Node expTree(String s) {
    Deque<Node> nodes = new ArrayDeque<>();    // stores nodes (new Node(val))
    Deque<Character> ops = new ArrayDeque<>(); // stores operators and parentheses

    for (final char c : s.toCharArray())
      if (Character.isDigit(c)) {
        nodes.push(new Node(c));
      } else if (c == '(') {
        ops.push(c);
      } else if (c == ')') {
        while (ops.peek() != '(')
          nodes.push(buildNode(ops.pop(), nodes.pop(), nodes.pop()));
        ops.pop(); // remove '('
      } else {     // c == '+' || c == '-' || c == '*' || c == '/'
        while (!ops.isEmpty() && compare(ops.peek(), c))
          nodes.push(buildNode(ops.pop(), nodes.pop(), nodes.pop()));
        ops.push(c);
      }

    while (!ops.isEmpty())
      nodes.push(buildNode(ops.pop(), nodes.pop(), nodes.pop()));

    return nodes.peek();
  }

  private Node buildNode(char op, Node right, Node left) {
    return new Node(op, left, right);
  }

  // return true if op1 is a operator and priority(op1) >= priority(op2)
  boolean compare(char op1, char op2) {
    if (op1 == '(' || op1 == ')')
      return false;
    return op1 == '*' || op1 == '/' || op2 == '+' || op2 == '-';
  }
}
