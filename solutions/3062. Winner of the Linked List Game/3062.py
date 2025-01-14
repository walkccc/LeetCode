class Solution:
  def gameResult(self, head: ListNode | None) -> str:
    even = 0
    odd = 0

    while head:
      if head.val > head.next.val:
        even += 1
      elif head.val < head.next.val:
        odd += 1
      head = head.next.next

    if even > odd:
      return 'Even'
    if even < odd:
      return 'Odd'
    return 'Tie'
