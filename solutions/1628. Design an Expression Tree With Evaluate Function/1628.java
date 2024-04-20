/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

abstract class Node {
  public abstract int evaluate();
  // define your fields here
};

class ExpNode extends Node {
  public ExpNode(String val, ExpNode left, ExpNode right) {
    this.val = val;
    this.left = left;
    this.right = right;
  }

  public int evaluate() {
    if (left == null && right == null)
      return Integer.parseInt(val);
    return op.get(val).apply(left.evaluate(), right.evaluate());
  }

  private static final Map<String, BinaryOperator<Integer>> op =
      Map.of("+", (a, b) -> a + b, "-", (a, b) -> a - b, "*", (a, b) -> a *b, "/", (a, b) -> a / b);
  private final String val;
  private final ExpNode left;
  private final ExpNode right;
}

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
  Node buildTree(String[] postfix) {
    Deque<ExpNode> stack = new ArrayDeque<>();

    for (final String val : postfix)
      if (val.equals("+") || val.equals("-") || val.equals("*") || val.equals("/")) {
        ExpNode right = stack.pop();
        ExpNode left = stack.pop();
        stack.push(new ExpNode(val, left, right));
      } else {
        stack.push(new ExpNode(val, null, null));
      }

    return stack.pop();
  }
}
