class Solution {
  public ListNode partition(ListNode head, int x) {
    ListNode beforeHead = new ListNode(0);
    ListNode afterHead = new ListNode(0);
    ListNode before = beforeHead;
    ListNode after = afterHead;

    for (; head != null; head = head.next)
      if (head.val < x) {
        before.next = head;
        before = head;
      } else {
        after.next = head;
        after = head;
      }

    after.next = null;
    before.next = afterHead.next;

    return beforeHead.next;
  }
}
