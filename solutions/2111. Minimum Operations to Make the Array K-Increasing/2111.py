class Solution:
  def kIncreasing(self, arr: list[int], k: int) -> int:
    def numReplaced(A: list[int]) -> int:
      tails = []
      for a in A:
        if not tails or tails[-1] <= a:
          tails.append(a)
        else:
          tails[bisect_right(tails, a)] = a
      return len(A) - len(tails)

    return sum(numReplaced(arr[i::k]) for i in range(k))
