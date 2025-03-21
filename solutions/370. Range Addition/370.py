class Solution:
  def getModifiedArray(
      self,
      length: int,
      updates: list[list[int]],
  ) -> list[int]:
    line = [0] * length

    for start, end, inc in updates:
      line[start] += inc
      if end + 1 < length:
        line[end + 1] -= inc

    return itertools.accumulate(line)
