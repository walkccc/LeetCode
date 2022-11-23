class Solution {
  public ListNode removeZeroSumSublists(ListNode head) {
    ListNode dummy = new ListNode(0, head);
    int prefix = 0;
    Map<Integer, ListNode> prefixToNode = new HashMap<>();
    prefixToNode.put(0, dummy);

    for (; head != null; head = head.next) {
      prefix += head.val;
      prefixToNode.put(prefix, head);
    }

    prefix = 0;

    for (head = dummy; head != null; head = head.next) {
      prefix += head.val;
      head.next = prefixToNode.get(prefix).next;
    }

    return dummy.next;
  }
}
