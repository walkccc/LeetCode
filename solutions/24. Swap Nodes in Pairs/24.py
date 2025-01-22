class Solution:
  def swapPairs(self, head: ListNode) -> ListNode:
    def getLength(head: ListNode) -> int:
      length = 0
      while head:
        length += 1
        head = head.next
      return length

    length = getLength(head)
    dummy = ListNode(0, head)
    prev = dummy
    curr = head

    for _ in range(length // 2):
      next = curr.next
      curr.next = next.next
      next.next = prev.next
      prev.next = next
      prev = curr
      curr = curr.next

    return dummy.next
