class Solution:
  def splitListToParts(self, root: ListNode, k: int) -> list[ListNode]:
    ans = [[] for _ in range(k)]
    length = 0
    curr = root
    while curr:
      length += 1
      curr = curr.next
    subLength = length // k
    remainder = length % k

    prev = None
    head = root

    for i in range(k):
      ans[i] = head
      for j in range(subLength + (1 if remainder > 0 else 0)):
        prev = head
        head = head.next
      if prev:
        prev.next = None
      remainder -= 1

    return ans
