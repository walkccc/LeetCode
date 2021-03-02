class Solution {
  public Node inorderSuccessor(Node node) {
    // the successor is somewhere upper in the tree
    if (node.right == null) {
      while (node.parent != null && node.parent.left != node)
        node = node.parent;
      return node.parent;
    }

    // the successor is somewhere lower in the right subtree
    node = node.right;
    while (node.left != null)
      node = node.left;
    return node;
  }
}
