class Solution:
  def oddEvenList(self, head: ListNode) -> ListNode:
    oddHead = ListNode(0)
    evenHead = ListNode(0)
    odd = oddHead
    even = evenHead
    isOdd = True

    while head:
      if isOdd:
        odd.next = head
        odd = head
      else:
        even.next = head
        even = head
      head = head.next
      isOdd = not isOdd

    even.next = None
    odd.next = evenHead.next
    return oddHead.next
