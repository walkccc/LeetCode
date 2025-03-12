# Definition for singly-linked list.
# class ListNode:
#   def __init__(self, val=0, next=None):
#     self.val = val
#     self.next = next

class Solution:
  def __init__(self, head: ListNode | None):
    self.head = head

  def getRandom(self) -> int:
    res = -1
    i = 1
    curr = self.head

    while curr:
      if random.randint(0, i - 1) == 0:
        res = curr.val
      curr = curr.next
      i += 1

    return res
