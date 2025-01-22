class Solution:
  def cycleLengthQueries(self, n: int, queries: list[list[int]]) -> list[int]:
    def getCycleLength(a: int, b: int):
      cycleLength = 1
      while a != b:
        if a > b:
          a //= 2
        else:
          b //= 2
        cycleLength += 1
      return cycleLength

    return [getCycleLength(*query) for query in queries]
