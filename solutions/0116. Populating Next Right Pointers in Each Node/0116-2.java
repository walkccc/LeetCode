class Solution {
  public Node connect(Node root) {
    Node node = root; // the node just above current needling

    while (node != null && node.left != null) {
      Node dummy = new Node(); // dummy node before needling
      // needle children of node
      for (Node needle = dummy; node != null; node = node.next) {
        needle.next = node.left;
        needle = needle.next;
        needle.next = node.right;
        needle = needle.next;
      }
      node = dummy.next; // move node to the next level
    }

    return root;
  }
}
