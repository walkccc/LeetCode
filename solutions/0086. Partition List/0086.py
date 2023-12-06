class Solution:
  def partition(self, head: ListNode, x: int) -> ListNode:
    beforeHead = ListNode(0)
    afterHead = ListNode(0)
    before = beforeHead
    after = afterHead

    while head:
      if head.val < x:
        before.next = head
        before = head
      else:
        after.next = head
        after = head
      head = head.next

    after.next = None
    before.next = afterHead.next

    return beforeHead.next
