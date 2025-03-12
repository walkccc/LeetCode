class Solution:
  def isItPossible(self, word1: str, word2: str) -> bool:
    count1 = collections.Counter(word1)
    count2 = collections.Counter(word2)
    distinct1 = len(count1)
    distinct2 = len(count2)

    for a in count1:
      for b in count2:
        if a == b:
          # Swapping the same letters won't change the number of distinct
          # letters in each string, so just check if `distinct1 == distinct2`.
          if distinct1 == distinct2:
            return True
          continue
        # The calculation is meaningful only when a != b
        # Swap a in word1 with b in word2.
        distinctAfterSwap1 = distinct1 - (count1[a] == 1) + (count1[b] == 0)
        distinctAfterSwap2 = distinct2 - (count2[b] == 1) + (count2[a] == 0)
        if distinctAfterSwap1 == distinctAfterSwap2:
          return True

    return False
