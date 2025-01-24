class Solution:
  def minDeletions(self, s: str) -> int:
    ans = 0
    count = collections.Counter(s)
    usedFreq = set()

    for freq in count.values():
      while freq > 0 and freq in usedFreq:
        freq -= 1  # Delete ('a' + i).
        ans += 1
      usedFreq.add(freq)

    return ans
