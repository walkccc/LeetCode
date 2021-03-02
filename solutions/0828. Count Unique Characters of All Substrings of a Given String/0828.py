class Solution:
  def uniqueLetterString(self, s: str) -> int:
    ans = 0
    count = 0
    lastCount = [0] * 26
    lastSeen = [-1] * 26

    for i, c in enumerate(s):
      c = ord(c) - ord('A')
      currentCount = i - lastSeen[c]
      count = count - lastCount[c] + currentCount
      lastCount[c] = currentCount
      lastSeen[c] = i
      ans += count

    return ans
