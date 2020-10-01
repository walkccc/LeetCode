class Solution {
  public Node connect(Node root) {
    Node node = root;
    Node cache = new Node(0);

    while (node != null) {
      Node curr = cache;
      while (node != null) {
        if (node.left != null) {
          curr.next = node.left;
          curr = curr.next;
        }
        if (node.right != null) {
          curr.next = node.right;
          curr = curr.next;
        }
        node = node.next;
      }
      node = cache.next;
      cache.next = null;
    }

    return root;
  }
}