class Solution:
  def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
    minDistance = math.inf
    firstMaIndex = -1
    prevMaIndex = -1
    index = 1
    prev = head  # point to index 0
    curr = head.next  # point to index 1

    while curr.next:
      if curr.val > prev.val and curr.val > curr.next.val or \
         curr.val < prev.val and curr.val < curr.next.val:
        if firstMaIndex == -1:  # only assign once
          firstMaIndex = index
        if prevMaIndex != -1:
          minDistance = min(minDistance, index - prevMaIndex)
        prevMaIndex = index
      prev = curr
      curr = curr.next
      index += 1

    if minDistance == math.inf:
      return [-1, -1]
    return [minDistance, prevMaIndex - firstMaIndex]
