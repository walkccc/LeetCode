class Solution {
  public ListNode sortList(ListNode head) {
    final int length = getLength(head);
    ListNode dummy = new ListNode(0, head);

    for (int k = 1; k < length; k *= 2) {
      ListNode curr = dummy.next;
      ListNode tail = dummy;
      while (curr != null) {
        ListNode l = curr;
        ListNode r = split(l, k);
        curr = split(r, k);
        ListNode[] merged = merge(l, r);
        tail.next = merged[0];
        tail = merged[1];
      }
    }

    return dummy.next;
  }

  private int getLength(ListNode head) {
    int length = 0;
    for (ListNode curr = head; curr != null; curr = curr.next)
      ++length;
    return length;
  }

  private ListNode split(ListNode head, int k) {
    while (--k > 0 && head != null)
      head = head.next;
    ListNode rest = head == null ? null : head.next;
    if (head != null)
      head.next = null;
    return rest;
  }

  private ListNode[] merge(ListNode l1, ListNode l2) {
    ListNode dummy = new ListNode(0);
    ListNode tail = dummy;

    while (l1 != null && l2 != null) {
      if (l1.val > l2.val) {
        ListNode temp = l1;
        l1 = l2;
        l2 = temp;
      }
      tail.next = l1;
      l1 = l1.next;
      tail = tail.next;
    }
    tail.next = l1 == null ? l2 : l1;
    while (tail.next != null)
      tail = tail.next;

    return new ListNode[] {dummy.next, tail};
  }
}
