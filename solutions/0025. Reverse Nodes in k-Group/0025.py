class Solution:
  def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
    if not head or k == 1:
      return head

    def getLength(head):
      length = 0
      while head:
        length += 1
        head = head.next
      return length

    dummy = ListNode(0)
    dummy.next = head
    length = getLength(head)
    prev = dummy
    curr = head

    for _ in range(length // k):
      for _ in range(k - 1):
        next = curr.next
        curr.next = next.next
        next.next = prev.next
        prev.next = next
      prev = curr
      curr = curr.next

    return dummy.next
