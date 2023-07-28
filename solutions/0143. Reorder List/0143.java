class Solution {
  public void reorderList(ListNode head) {
    if (head == null || head.next == null)
      return;

    ListNode mid = findMid(head);
    ListNode reversed = reverse(mid);
    merge(head, reversed);
  }

  private ListNode findMid(ListNode head) {
    ListNode prev = null;
    ListNode slow = head;
    ListNode fast = head;

    while (fast != null && fast.next != null) {
      prev = slow;
      slow = slow.next;
      fast = fast.next.next;
    }
    prev.next = null;

    return slow;
  }

  private ListNode reverse(ListNode head) {
    ListNode prev = null;
    ListNode curr = head;

    while (curr != null) {
      ListNode next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }

  private void merge(ListNode l1, ListNode l2) {
    while (l2 != null) {
      ListNode next = l1.next;
      l1.next = l2;
      l1 = l2;
      l2 = next;
    }
  }
}
