class Solution:
  def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
    curr = head.next

    while curr:
      running = curr
      summ = 0
      while running.val:
        summ += running.val
        running = running.next

      curr.val = summ
      curr.next = running.next
      curr = running.next

    return head.next
