import java.util.Stack;

import org.w3c.dom.Node;

class Solution {
  public Node treeToDoublyList(Node root) {
    // very similar to 94. Binary Tree Inorder Traversal
    if (root == null)
      return null;

    Stack<Node> stack = new Stack<>();
    Node first = null;
    Node prev = null;

    while (root != null || !stack.isEmpty()) {
      while (root != null) {
        stack.push(root);
        root = root.left;
      }
      root = stack.pop();
      if (first == null)
        first = root;
      if (prev) {
        prev.right = root;
        root.left = prev;
      }
      prev = root;
      root = root.right;
    }

    prev.right = first;
    first.left = prev;

    return first;
  }
}