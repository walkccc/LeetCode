class Solution:
  def reverseEvenLengthGroups(self, head: ListNode | None) -> ListNode | None:
    # prev -> (head -> ... -> tail) -> next -> ...
    dummy = ListNode(0, head)
    prev = dummy
    tail = head
    next = head.next
    groupLength = 1

    def getTailAndLength(head: ListNode | None, groupLength: int) -> tuple[ListNode | None, int]:
      length = 1
      tail = head
      while length < groupLength and tail.next:
        tail = tail.next
        length += 1
      return tail, length

    def reverse(head: ListNode | None) -> ListNode | None:
      prev = None
      while head:
        next = head.next
        head.next = prev
        prev = head
        head = next
      return prev

    while True:
      if groupLength % 2 == 1:
        prev.next = head
        prev = tail
      else:
        tail.next = None
        prev.next = reverse(head)
        # Prev -> (tail -> ... -> head) -> next -> ...
        head.next = next
        prev = head
      if not next:
        break
      head = next
      tail, length = getTailAndLength(head, groupLength + 1)
      next = tail.next
      groupLength = length

    return dummy.next
