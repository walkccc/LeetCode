class Solution:
  def maxBoxesInWarehouse(self, boxes: list[int], warehouse: list[int]) -> int:
    l = 0
    r = len(warehouse) - 1

    for box in sorted(boxes, reverse=True):
      if l > r:
        return len(warehouse)
      if box <= warehouse[l]:
        l += 1
      elif box <= warehouse[r]:
        r -= 1

    return l + (len(warehouse) - r - 1)
