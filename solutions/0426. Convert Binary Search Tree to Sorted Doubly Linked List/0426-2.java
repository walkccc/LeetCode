class Solution {
  // Similar to 94. Binary Tree Inorder Traversal
  public Node treeToDoublyList(Node root) {
    if (root == null)
      return null;

    Deque<Node> stack = new ArrayDeque<>();
    Node first = null;
    Node pred = null;

    while (root != null || !stack.isEmpty()) {
      while (root != null) {
        stack.push(root);
        root = root.left;
      }
      root = stack.pop();
      if (first == null)
        first = root;
      if (pred != null) {
        pred.right = root;
        root.left = pred;
      }
      pred = root;
      root = root.right;
    }

    pred.right = first;
    first.left = pred;
    return first;
  }
}
