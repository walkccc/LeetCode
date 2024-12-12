class Solution:
  def sameEndSubstringCount(
      self,
      s: str,
      queries: list[list[int]],
  ) -> list[int]:
    count = collections.Counter()
    # counts[i] := the count of s[0..i)
    counts = [count.copy()]

    for c in s:
      count[c] += 1
      counts.append(count.copy())

    ans = []

    for l, r in queries:
      sameEndCount = 0
      for c in string.ascii_lowercase:
        #   the count of s[0..r] - the count of s[0..l - 1]
        # = the count of s[l..r]
        freq = counts[r + 1][c] - counts[l][c]
        #   C(freq, 2) + freq
        # = freq * (freq - 1) / 2 + freq
        # = freq * (freq + 1) / 2
        sameEndCount += freq * (freq + 1) // 2
      ans.append(sameEndCount)

    return ans
