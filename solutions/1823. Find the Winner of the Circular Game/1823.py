class Solution:
  def findTheWinner(self, n: int, k: int) -> int:
    # True if i-th friend is left
    friends = [False] * n

    friendCount = n
    fp = 0  # friends' index

    while friendCount > 1:
      for _ in range(k):
        while friends[fp % n]:  # The friend is not there.
          fp += 1  # Point to the next one.
        fp += 1
      friends[(fp - 1) % n] = True
      friendCount -= 1

    fp = 0
    while friends[fp]:
      fp += 1

    return fp + 1
