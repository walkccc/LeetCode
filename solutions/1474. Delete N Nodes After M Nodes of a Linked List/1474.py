class Solution:
  def deleteNodes(
      self,
      head: ListNode | None,
      m: int,
      n: int,
  ) -> ListNode | None:
    curr = head
    prev = None  # prev.next == curr

    while curr:
      # Set the m-th node as `prev`.
      for _ in range(m):
        if not curr:
          break
        prev = curr
        curr = curr.next
      # Set the (m + n + 1)-th node as `curr`.
      for _ in range(n):
        if not curr:
          break
        curr = curr.next
      # Delete the nodes [m + 1..n - 1].
      prev.next = curr

    return head
