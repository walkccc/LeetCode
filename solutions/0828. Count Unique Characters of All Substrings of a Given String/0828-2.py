class Solution:
  def uniqueLetterString(self, s: str) -> int:
    ans = 0
    # lastSeen[c] := last index of c
    lastSeen = collections.defaultdict(lambda: -1)
    # prevSeen[c] := previous of last index of c
    prevLastSeen = collections.defaultdict(lambda: -1)

    for i, c in enumerate(s):
      if c in lastSeen:
        ans += (i - lastSeen[c]) * (lastSeen[c] - prevLastSeen[c])
      prevLastSeen[c] = lastSeen[c]
      lastSeen[c] = i

    for c in string.ascii_uppercase:
      ans += (len(s) - lastSeen[c]) * (lastSeen[c] - prevLastSeen[c])

    return ans
