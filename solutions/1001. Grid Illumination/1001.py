class Solution:
  def gridIllumination(
      self,
      n: int,
      lamps: list[list[int]],
      queries: list[list[int]],
  ) -> list[int]:
    ans = []
    rows = collections.Counter()
    cols = collections.Counter()
    diag1 = collections.Counter()
    diag2 = collections.Counter()
    lampsSet = set()

    for i, j in lamps:
      if (i, j) not in lampsSet:
        lampsSet.add((i, j))
        rows[i] += 1
        cols[j] += 1
        diag1[i + j] += 1
        diag2[i - j] += 1

    for i, j in queries:
      if rows[i] or cols[j] or diag1[i + j] or diag2[i - j]:
        ans.append(1)
        for y in range(max(0, i - 1), min(n, i + 2)):
          for x in range(max(0, j - 1), min(n, j + 2)):
            if (y, x) in lampsSet:
              lampsSet.remove((y, x))
              rows[y] -= 1
              cols[x] -= 1
              diag1[y + x] -= 1
              diag2[y - x] -= 1
      else:
        ans.append(0)

    return ans
