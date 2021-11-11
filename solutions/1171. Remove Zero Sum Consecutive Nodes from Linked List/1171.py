class Solution:
  def removeZeroSumSublists(self, head: ListNode) -> ListNode:
    dummy = ListNode(0, head)
    prefix = 0
    prefixToNode = {0: dummy}

    while head:
      prefix += head.val
      prefixToNode[prefix] = head
      head = head.next

    prefix = 0
    head = dummy

    while head:
      prefix += head.val
      head.next = prefixToNode[prefix].next
      head = head.next

    return dummy.next
