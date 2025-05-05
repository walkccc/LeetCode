class Solution {
  public ListNode frequenciesOfElements(ListNode head) {
    HashMap<Integer, Integer> count = new HashMap<>();
    ListNode curr = head;

    while (curr != null) {
      count.merge(curr.val, 1, Integer::sum);
      curr = curr.next;
    }

    ListNode dummy = new ListNode(0);
    ListNode tail = dummy;

    for (final int freq : count.values()) {
      tail.next = new ListNode(freq);
      tail = tail.next;
    }

    return dummy.next;
  }
}
