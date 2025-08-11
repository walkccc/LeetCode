class Solution:
  def circularGameLosers(self, n: int, k: int) -> list[int]:
    seen = [False] * n
    friendIndex = 0
    turn = 1

    while not seen[friendIndex]:
      seen[friendIndex] = True
      friendIndex += turn * k
      friendIndex %= n
      turn += 1

    return [friendIndex + 1
            for friendIndex in range(n)
            if not seen[friendIndex]]
