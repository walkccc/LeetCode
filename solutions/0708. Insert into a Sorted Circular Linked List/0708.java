class Solution {
  public Node insert(Node head, int insertVal) {
    if (head == null) {
      Node newNode = new Node(insertVal);
      newNode.next = newNode;
      return newNode;
    }

    Node prev = head;
    Node curr = head.next;

    while (curr != head) {
      // case 1: min <= insertVal <= max
      // case 2: insertVal >= max or insertVal <= min
      if ((prev.val <= insertVal && insertVal <= curr.val) ||
          (prev.val > curr.val && // prev is max, curr is min
           (insertVal >= prev.val || insertVal <= curr.val))) {
        // insert the node between prev and curr
        prev.next = new Node(insertVal, curr);
        return head;
      }

      prev = prev.next;
      curr = curr.next;
    }

    // all vals in list are identical
    prev.next = new Node(insertVal, curr);
    return head;
  }
}
