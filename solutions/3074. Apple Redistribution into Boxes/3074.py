class Solution:
  def minimumBoxes(self, apple: list[int], capacity: list[int]) -> int:
    appleSum = sum(apple)
    capacitySum = 0

    for i, c in enumerate(sorted(capacity, reverse=True)):
      capacitySum += c
      if capacitySum >= appleSum:
        return i + 1

    return len(capacity)
