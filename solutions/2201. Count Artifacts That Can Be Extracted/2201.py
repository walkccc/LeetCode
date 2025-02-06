class Solution:
  def digArtifacts(
      self,
      n: int,
      artifacts: list[list[int]],
      dig: list[list[int]],
  ) -> int:
    digged = set((r, c) for r, c in dig)

    def canExtract(a: list[int]) -> bool:
      for i in range(a[0], a[2] + 1):
        for j in range(a[1], a[3] + 1):
          if (i, j) not in digged:
            return False
      return True

    return sum(canExtract(a) for a in artifacts)
