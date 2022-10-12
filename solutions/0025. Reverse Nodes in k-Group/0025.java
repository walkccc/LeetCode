class Solution {
  public ListNode reverseKGroup(ListNode head, int k) {
    if (head == null)
      return null;

    ListNode tail = head;

    for (int i = 0; i < k; ++i) {
      if (tail == null) // Less than k nodes, do nothing
        return head;
      tail = tail.next;
    }

    ListNode newHead = reverse(head, tail);
    head.next = reverseKGroup(tail, k);
    return newHead;
  }

  // Reverses [head, tail)
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
