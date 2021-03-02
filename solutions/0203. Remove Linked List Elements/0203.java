class Solution {
  public ListNode removeElements(ListNode head, int val) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode prev = dummy;

    for (; head != null; head = head.next)
      if (head.val != val) {
        prev.next = head;
        prev = prev.next;
      }
    prev.next = null; // in case the last val == val

    return dummy.next;
  }
}
