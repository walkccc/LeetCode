class Solution {
  public Node connect(Node root) {
    Node node = root; // The node just above current needling

    while (node != null && node.left != null) {
      Node dummy = new Node(); // Dummy node before needling
      // Needle children of node
      for (Node needle = dummy; node != null; node = node.next) {
        needle.next = node.left;
        needle = needle.next;
        needle.next = node.right;
        needle = needle.next;
      }
      node = dummy.next; // Move node to the next level
    }

    return root;
  }
}
