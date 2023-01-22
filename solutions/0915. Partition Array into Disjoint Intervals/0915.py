class Solution:
  def partitionDisjoint(self, A: List[int]) -> int:
    n = len(A)
    mini = [0] * (n - 1) + [A[-1]]
    maxi = -math.inf

    for i in range(n - 2, - 1, -1):
      mini[i] = min(mini[i + 1], A[i])

    for i, a in enumerate(A):
      maxi = max(maxi, a)
      if maxi <= mini[i + 1]:
        return i + 1
