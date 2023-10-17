class Solution:
  def recoverArray(self, n: int, sums: List[int]) -> List[int]:
    def recover(sums: List[int]) -> List[int]:
      if len(sums) == 1:
        return []

      count = collections.Counter(sums)
      # Either num or -num must be in the final array.
      #  num + sumsExcludingNum = sumsIncludingNum
      # -num + sumsIncludingNum = sumsExcludingNum
      num = sums[1] - sums[0]
      sumsExcludingNum = []
      sumsIncludingNum = []
      chooseSumsExcludingNum = True

      for summ in sums:
        if count[summ] == 0:
          continue
        count[summ] -= 1
        count[summ + num] -= 1
        sumsExcludingNum.append(summ)
        sumsIncludingNum.append(summ + num)
        if summ + num == 0:
          chooseSumsExcludingNum = False

      # Choose `sumsExludingNum` by default since we want to gradually strip
      # `num` from each sum in `sums` to have the final array. However, we should
      # always choose the group of sums with 0 since it's a must-have.
      return [num] + recover(sumsExcludingNum) if chooseSumsExcludingNum \
          else [-num] + recover(sumsIncludingNum)

    return recover(sorted(sums))
