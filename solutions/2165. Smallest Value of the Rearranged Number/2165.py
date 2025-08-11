class Solution:
  def smallestNumber(self, num: int) -> int:
    s = sorted(str(abs(num)), reverse=num < 0)
    firstNonZeroIndex = next((i for i, c in enumerate(s) if c != '0'), 0)
    s[0], s[firstNonZeroIndex] = s[firstNonZeroIndex], s[0]
    return int(''.join(s)) * (-1 if num < 0 else 1)
