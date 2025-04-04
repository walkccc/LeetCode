class Solution:
  def reverseBetween(
      self,
      head: ListNode | None,
      left: int,
      right: int,
  ) -> ListNode | None:
    if left == 1:
      return self.reverseN(head, right)

    head.next = self.reverseBetween(head.next, left - 1, right - 1)
    return head

  def reverseN(self, head: ListNode | None, n: int) -> ListNode | None:
    if n == 1:
      return head

    newHead = self.reverseN(head.next, n - 1)
    headNext = head.next
    head.next = headNext.next
    headNext.next = head
    return newHead
