class Solution:
  def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
    n = len(arr1)
    a = [arr1[i] + arr2[i] + i for i in range(n)]
    b = [arr1[i] + arr2[i] - i for i in range(n)]
    c = [arr1[i] - arr2[i] + i for i in range(n)]
    d = [arr1[i] - arr2[i] - i for i in range(n)]
    return max(map(lambda x: max(x) - min(x), (a, b, c, d)))
