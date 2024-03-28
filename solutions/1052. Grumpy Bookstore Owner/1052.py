class Solution:
  def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
    satisfied = sum(c for i, c in enumerate(customers) if grumpy[i] == 0)
    madeSatisfied = 0
    windowSatisfied = 0

    for i, customer in enumerate(customers):
      if grumpy[i] == 1:
        windowSatisfied += customer
      if i >= X and grumpy[i - X] == 1:
        windowSatisfied -= customers[i - X]
      madeSatisfied = max(madeSatisfied, windowSatisfied)

    return satisfied + madeSatisfied
