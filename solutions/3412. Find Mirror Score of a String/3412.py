class Solution:
  def calculateScore(self, s: str) -> int:
    ans = 0
    indices = [[] for _ in range(26)]

    for i, c in enumerate(s):
      index = ord(c) - ord('a')
      oppositeIndex = 25 - index
      if indices[oppositeIndex]:
        ans += i - indices[oppositeIndex].pop()
      else:
        indices[index].append(i)

    return ans
