class Solution {
  public Node connect(Node root) {
    Node node = root;

    while (node != null && node.left != null) {
      Node next = node.left;
      while (node != null) {
        node.left.next = node.right;
        node.right.next = node.next == null ? null : node.next.left;
        node = node.next;
      }
      node = next;
    }

    return root;
  }
}