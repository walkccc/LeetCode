class Solution:
  def maxBoxesInWarehouse(self, boxes: list[int], warehouse: list[int]) -> int:
    i = 0  # warehouse's index

    for box in sorted(boxes, reverse=True):
      if i < len(warehouse) and warehouse[i] >= box:
        i += 1

    return i
