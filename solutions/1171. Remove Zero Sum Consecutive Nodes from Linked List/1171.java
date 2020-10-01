class Solution {
  public ListNode removeZeroSumSublists(ListNode head) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    int prefixSum = 0;
    Map<Integer, ListNode> prefixSumToNode = new HashMap<>();
    prefixSumToNode.put(0, dummy);

    for (; head != null; head = head.next) {
      prefixSum += head.val;
      prefixSumToNode.put(prefixSum, head);
    }

    prefixSum = 0;

    for (head = dummy; head != null; head = head.next) {
      prefixSum += head.val;
      head.next = prefixSumToNode.get(prefixSum).next;
    }

    return dummy.next;
  }
}