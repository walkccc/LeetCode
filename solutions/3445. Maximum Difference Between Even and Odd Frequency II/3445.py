class Solution:
  def maxDifference(self, s: str, k: int) -> int:
    ans = -math.inf
    permutations = [(a, b) for a in '01234' for b in '01234' if a != b]

    for a, b in permutations:
      # minDiff[(parityA, parityB)] := min(a - b) of all valid windows with
      # parityA and parityB
      minDiff = collections.defaultdict(lambda: math.inf)
      prefixA = [0]  # prefixA[i] := the number of 'a's in s[0..i)
      prefixB = [0]  # prefixB[i] := the number of 'b's in s[0..i)

      l = 0
      for r, c in enumerate(s):
        prefixA.append(prefixA[-1] + int(c == a))
        prefixB.append(prefixB[-1] + int(c == b))
        while (r - l + 1 >= k and  # the window size >= k
               prefixA[l] < prefixA[-1] and  # the number of 'a's > 0
               prefixB[l] < prefixB[-1]):  # the number of 'b's > 0
          paritiesKey = (prefixA[l] % 2, prefixB[l] % 2)
          minDiff[paritiesKey] = min(minDiff[paritiesKey],
                                     prefixA[l] - prefixB[l])
          l += 1
        ans = max(ans, (prefixA[-1] - prefixB[-1]) -
                  minDiff[(1 - prefixA[-1] % 2, prefixB[-1] % 2)])

    return ans
