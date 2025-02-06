class Solution:
  def garbageCollection(self, garbage: list[str], travel: list[int]) -> int:
    prefix = list(itertools.accumulate(travel))

    def getTime(c: str) -> int:
      characterCount = 0
      lastIndex = -1
      for i, s in enumerate(garbage):
        if any(g == c for g in s):
          lastIndex = i
        characterCount += s.count(c)
      return characterCount + (0 if lastIndex <= 0 else prefix[lastIndex - 1])

    return getTime('M') + getTime('P') + getTime('G')
