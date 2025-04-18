class Solution:
  def numDifferentIntegers(self, word: str) -> int:
    nums = set()
    curr = []

    for c in word:
      if c.isdigit():
        curr.append(c)
      elif curr:
        nums.add(''.join(self._removeLeadingZeros(curr)))
        curr = []

    if curr:
      nums.add(''.join(self._removeLeadingZeros(curr)))

    return len(nums)

  def _removeLeadingZeros(self, s: str) -> str:
    index = next((i for i, c in enumerate(s) if c != '0'), -1)
    return ['0'] if index == -1 else s[index:]
