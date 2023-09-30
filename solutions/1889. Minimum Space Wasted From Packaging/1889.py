class Solution:
  def minWastedSpace(self, packages: List[int], boxes: List[List[int]]) -> int:
    ans = math.inf

    packages.sort()

    for box in boxes:
      box.sort()
      if box[-1] < packages[-1]:
        continue
      accu = 0
      i = 0
      for b in box:
        j = bisect.bisect(packages, b, i)
        accu += b * (j - i)
        i = j
      ans = min(ans, accu)

    return -1 if ans == math.inf else (ans - sum(packages)) % int(1e9 + 7)
