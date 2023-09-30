class Solution {
  public ListNode removeNodes(ListNode head) {
    if (head == null)
      return null;
    head.next = removeNodes(head.next);
    return head.next != null && head.val < head.next.val ? head.next : head;
  }
}
