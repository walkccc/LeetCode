class Solution {
  public ListNode mergeKLists(ListNode[] lists) {
    ListNode dummy = new ListNode(0);
    ListNode curr = dummy;
    Queue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val); // min-heap

    for (final ListNode list : lists)
      if (list != null)
        pq.offer(list);

    while (!pq.isEmpty()) {
      ListNode minNode = pq.poll();
      if (minNode.next != null)
        pq.offer(minNode.next);
      curr.next = minNode;
      curr = curr.next;
    }

    return dummy.next;
  }
}
