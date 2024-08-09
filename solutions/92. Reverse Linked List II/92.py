class Solution:
  def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
    if left == 1:
      return self.reverseN(head, right)

    head.next = self.reverseBetween(head.next, left - 1, right - 1)
    return head

  def reverseN(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    if n == 1:
      return head

    newHead = self.reverseN(head.next, n - 1)
    headNext = head.next
    head.next = headNext.next
    headNext.next = head
    return newHead
