# The knows API is already defined for you.
# Returns a bool, whether a knows b
# Def knows(a: int, b: int) -> bool:


class Solution:
  def findCelebrity(self, n: int) -> int:
    candidate = 0

    # Everyone knows the celebrity.
    for i in range(1, n):
      if knows(candidate, i):
        candidate = i

    # The candidate knows nobody and everyone knows the celebrity.
    for i in range(n):
      if i < candidate and knows(candidate, i) or not knows(i, candidate):
        return -1
      if i > candidate and not knows(i, candidate):
        return -1

    return candidate
