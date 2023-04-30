class Solution:
  def kIncreasing(self, arr: List[int], k: int) -> int:
    def numReplaced(A: List[int]) -> int:
      tail = []
      for a in A:
        if not tail or tail[-1] <= a:
          tail.append(a)
        else:
          tail[bisect_right(tail, a)] = a
      return len(A) - len(tail)

    return sum(numReplaced(arr[i::k]) for i in range(k))
