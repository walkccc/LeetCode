class Solution:
  def numberOfBeams(self, bank: list[str]) -> int:
    ans = 0
    prevOnes = 0

    for row in bank:
      ones = row.count('1')
      if ones:
        ans += prevOnes * ones
        prevOnes = ones

    return ans
