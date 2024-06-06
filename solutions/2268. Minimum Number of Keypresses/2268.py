class Solution:
  def minimumKeypresses(self, s: str) -> int:
    return sum(c * (i // 9 + 1)
               for i, c in enumerate(sorted(Counter(s).values(), reverse=True)))
