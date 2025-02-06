class Solution:
  def mergeInBetween(
      self,
      list1: ListNode,
      a: int,
      b: int,
      list2: ListNode,
  ) -> ListNode:
    nodeBeforeA = list1
    for i in range(a - 1):
      nodeBeforeA = nodeBeforeA.next

    nodeB = nodeBeforeA.next
    for i in range(b - a):
      nodeB = nodeB.next

    nodeBeforeA.next = list2
    lastNodeInList2 = list2

    while lastNodeInList2.next:
      lastNodeInList2 = lastNodeInList2.next

    lastNodeInList2.next = nodeB.next
    nodeB.next = None
    return list1
