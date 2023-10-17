class Solution:
  def divisibilityArray(self, word: str, m: int) -> List[int]:
    ans = []
    prevRemainder = 0

    for c in word:
      remainder = (prevRemainder * 10 + int(c)) % m
      ans.append(1 if remainder == 0 else 0)
      prevRemainder = remainder

    return ans
