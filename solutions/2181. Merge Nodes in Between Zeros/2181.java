class Solution {
  public ListNode mergeNodes(ListNode head) {
    if (head == null)
      return null;
    if (head.next.val == 0) {
      ListNode node = new ListNode(head.val);
      node.next = mergeNodes(head.next.next);
      return node;
    }

    ListNode next = mergeNodes(head.next);
    next.val += head.val;
    return next;
  }
}
