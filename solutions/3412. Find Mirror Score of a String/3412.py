class Solution:
  def calculateScore(self, s: str) -> int:
    ans = 0
    indices = [[] for _ in range(26)]

    for i, c in enumerate(s):
      index = string.ascii_lowercase.index(c)
      oppositeIndex = 25 - index
      if indices[oppositeIndex]:
        ans += i - indices[oppositeIndex].pop()
      else:
        indices[index].append(i)

    return ans
