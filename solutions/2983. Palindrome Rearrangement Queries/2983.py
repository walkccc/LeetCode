class Solution:
  def canMakePalindromeQueries(
      self,
      s: str,
      queries: list[list[int]],
  ) -> list[bool]:
    n = len(s)
    # mirroredDiffs[i] := the number of different letters between the first i
    # letters of s[0..n / 2) and the first i letters of s[n / 2..n)[::-1]
    mirroredDiffs = self._getMirroredDiffs(s)
    # counts[i] := the count of s[0..i)
    counts = self._getCounts(s)
    ans = []

    def subtractArrays(a: list[int], b: list[int]):
      return [x - y for x, y in zip(a, b)]

    for a, b, c, d in queries:
      # Use left-closed, right-open intervals to facilitate the calculation.
      #   ...... [a, b) ...|... [rb, ra) ......
      #   .... [rd, rc) .....|..... [c, d) ....
      b += 1
      d += 1
      ra = n - a  # the reflected index of a in s[n / 2..n)
      rb = n - b  # the reflected index of b in s[n / 2..n)
      rc = n - c  # the reflected index of c in s[n / 2..n)
      rd = n - d  # the reflected index of d in s[n / 2..n)
      # No difference is allowed outside the query ranges.
      if ((min(a, rd) > 0 and mirroredDiffs[min(a, rd)] > 0) or
         (n // 2 > max(b, rc) and
          mirroredDiffs[n // 2] - mirroredDiffs[max(b, rc)] > 0) or
         (rd > b and mirroredDiffs[rd] - mirroredDiffs[b] > 0) or
         (a > rc and mirroredDiffs[a] - mirroredDiffs[rc] > 0)):
        ans.append(False)
      else:
        # The `count` map of the intersection of [a, b) and [rd, rc) in
        # s[0..n / 2) must equate to the `count` map of the intersection of
        # [c, d) and [rb, ra) in s[n / 2..n).
        leftRangeCount = subtractArrays(counts[b], counts[a])
        rightRangeCount = subtractArrays(counts[d], counts[c])
        if a > rd:
          rightRangeCount = subtractArrays(
              rightRangeCount, subtractArrays(counts[min(a, rc)], counts[rd]))
        if rc > b:
          rightRangeCount = subtractArrays(
              rightRangeCount, subtractArrays(counts[rc], counts[max(b, rd)]))
        if c > rb:
          leftRangeCount = subtractArrays(
              leftRangeCount, subtractArrays(counts[min(c, ra)], counts[rb]))
        if ra > d:
          leftRangeCount = subtractArrays(
              leftRangeCount, subtractArrays(counts[ra], counts[max(d, rb)]))
        ans.append(min(leftRangeCount) >= 0
                   and min(rightRangeCount) >= 0
                   and leftRangeCount == rightRangeCount)

    return ans

  def _getMirroredDiffs(self, s: str) -> list[int]:
    diffs = [0]
    for i, j in zip(range(len(s)), reversed(range(len(s)))):
      if i >= j:
        break
      diffs.append(diffs[-1] + (s[i] != s[j]))
    return diffs

  def _getCounts(self, s: str) -> list[list[int]]:
    count = [0] * 26
    counts = [count.copy()]
    for c in s:
      count[string.ascii_lowercase.index(c)] += 1
      counts.append(count.copy())
    return counts
