class Solution {
  public ListNode deleteDuplicatesUnsorted(ListNode head) {
    ListNode dummy = new ListNode(0, head);
    Map<Integer, Integer> count = new HashMap<>();

    for (ListNode curr = head; curr != null; curr = curr.next)
      count.merge(curr.val, 1, Integer::sum);

    ListNode curr = dummy;

    while (curr != null) {
      while (curr.next != null && count.containsKey(curr.next.val) && count.get(curr.next.val) > 1)
        curr.next = curr.next.next;
      curr = curr.next;
    }

    return dummy.next;
  }
}
