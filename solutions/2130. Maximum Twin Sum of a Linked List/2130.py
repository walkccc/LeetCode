class Solution:
  def pairSum(self, head: ListNode | None) -> int:
    def reverseList(head: ListNode) -> ListNode:
      prev = None
      while head:
        next = head.next
        head.next = prev
        prev = head
        head = next
      return prev

    ans = 0
    slow = head
    fast = head

    # `slow` points to the start of the second half.
    while fast and fast.next:
      slow = slow.next
      fast = fast.next.next

    # `tail` points to the end of the reversed second half.
    tail = reverseList(slow)

    while tail:
      ans = max(ans, head.val + tail.val)
      head = head.next
      tail = tail.next

    return ans
