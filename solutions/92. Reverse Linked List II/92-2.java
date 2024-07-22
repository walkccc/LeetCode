class Solution {
  public ListNode reverseBetween(ListNode head, int m, int n) {
    if (head == null || m == n)
      return head;

    ListNode dummy = new ListNode(0, head);
    ListNode prev = dummy;

    for (int i = 0; i < m - 1; ++i)
      prev = prev.next; // Point to the node before the sublist [m, n].

    ListNode tail = prev.next; // Be the tail of the sublist [m, n].

    // Reverse the sublist [m, n] one by one.
    for (int i = 0; i < n - m; ++i) {
      ListNode cache = tail.next;
      tail.next = cache.next;
      cache.next = prev.next;
      prev.next = cache;
    }

    return dummy.next;
  }
}
