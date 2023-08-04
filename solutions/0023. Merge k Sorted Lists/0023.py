from queue import PriorityQueue


class Solution:
  def mergeKLists(self, lists: List[ListNode]) -> ListNode:
    dummy = ListNode(0)
    curr = dummy
    pq = PriorityQueue()

    for i, lst in enumerate(lists):
      if lst:
        pq.put((lst.val, i, lst))

    while not pq.empty():
      _, i, minNode = pq.get()
      if minNode.next:
        pq.put((minNode.next.val, i, minNode.next))
      curr.next = minNode
      curr = curr.next

    return dummy.next
