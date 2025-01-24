class Solution:
  def maxBoxesInWarehouse(self, boxes: list[int], warehouse: list[int]) -> int:
    realWarehouse = [warehouse[0]]

    for i in range(1, len(warehouse)):
      realWarehouse.append(min(realWarehouse[-1], warehouse[i]))

    boxes.sort()
    i = 0  # boxes' index
    for height in reversed(realWarehouse):
      if i < len(boxes) and boxes[i] <= height:
        i += 1

    return i
