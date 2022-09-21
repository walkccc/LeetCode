class Solution {
  public Node treeToDoublyList(Node root) {
    if (root == null)
      return null;

    Node leftHead = treeToDoublyList(root.left);
    Node rightHead = treeToDoublyList(root.right);
    root.left = root;
    root.right = root;
    return connect(connect(leftHead, root), rightHead);
  }

  private Node connect(Node node1, Node node2) {
    if (node1 == null)
      return node2;
    if (node2 == null)
      return node1;

    Node tail1 = node1.left;
    Node tail2 = node2.left;

    // connect node1's tail with node2
    tail1.right = node2;
    node2.left = tail1;

    // connect node2's tail with node1
    tail2.right = node1;
    node1.left = tail2;
    return node1;
  }
}
