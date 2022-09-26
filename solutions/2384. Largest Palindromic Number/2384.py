class Solution:
  def largestPalindromic(self, num: str) -> str:
    count = Counter(num)
    firstHalf = ''.join(count[i] // 2 * i for i in '9876543210').lstrip('0')
    mid = self._getMid(count)
    return (firstHalf + mid + firstHalf[::-1]) or '0'

  def _getMid(self, count: Dict[str, int]) -> str:
    for c in '9876543210':
      if count[c] & 1:
        return c
    return ''
