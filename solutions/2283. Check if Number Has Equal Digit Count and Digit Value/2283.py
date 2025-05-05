class Solution:
  def digitCount(self, num: str) -> bool:
    count = collections.Counter(num)
    return all(count[str(i)] == int(digit)
               for i, digit in enumerate(num))
