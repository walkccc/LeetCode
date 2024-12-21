class Solution:
  def doubleIt(self, head: ListNode | None) -> ListNode | None:
    if head.val >= 5:
      head = ListNode(0, head)

    curr = head

    while curr:
      curr.val *= 2
      curr.val %= 10
      if curr.next and curr.next.val >= 5:
        curr.val += 1
      curr = curr.next

    return head
