class Solution:
  def nextGreatestLetter(self, letters: List[str], target: str) -> str:
    l = 0
    r = len(letters)

    while l < r:
      m = (l + r) >> 1
      if letters[m] <= target:
        l = m + 1
      else:
        r = m

    return letters[l % len(letters)]
