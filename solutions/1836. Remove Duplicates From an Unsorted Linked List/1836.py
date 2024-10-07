class Solution:
  def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
    dummy = ListNode(0, head)
    count = collections.Counter()

    curr = head
    while curr:
      count[curr.val] += 1
      curr = curr.next

    curr = dummy

    while curr:
      while curr.next and curr.next.val in count and count[curr.next.val] > 1:
        curr.next = curr.next.next
      curr = curr.next

    return dummy.next
