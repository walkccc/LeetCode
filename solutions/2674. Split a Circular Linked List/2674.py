class Solution:
  def splitCircularLinkedList(self, list: Optional[ListNode]) -> List[Optional[ListNode]]:
    slow = list
    fast = list

    # Point `slow` to the last node in the first half.
    while fast.next != list and fast.next.next != list:
      slow = slow.next
      fast = fast.next.next

    # Circle back the second half.
    secondHead = slow.next
    if fast.next == list:
      fast.next = secondHead
    else:
      fast.next.next = secondHead

    # Circle back the first half.
    slow.next = list

    return [list, secondHead]
