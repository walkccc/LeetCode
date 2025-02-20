class Solution:
  def minimumLength(self, s: str) -> int:
    count = collections.Counter(s)
    return sum(2 if freq % 2 == 0 else 1 for freq in count.values())
