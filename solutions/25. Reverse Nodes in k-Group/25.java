class Solution {
  public ListNode reverseKGroup(ListNode head, int k) {
    if (head == null)
      return null;

    ListNode tail = head;

    for (int i = 0; i < k; ++i) {
      // There are less than k nodes in the list, do nothing.
      if (tail == null)
        return head;
      tail = tail.next;
    }

    ListNode newHead = reverse(head, tail);
    head.next = reverseKGroup(tail, k);
    return newHead;
  }

  // Reverses [head, tail).
  private ListNode reverse(ListNode head, ListNode tail) {
    ListNode prev = null;
    ListNode curr = head;
    while (curr != tail) {
      ListNode next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
}
