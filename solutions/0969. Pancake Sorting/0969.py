class Solution:
  def pancakeSort(self, A: List[int]) -> List[int]:
    ans = []

    for target in range(len(A), 0, -1):
      index = A.index(target)
      A[:index + 1] = A[:index + 1][::-1]
      A[:target] = A[:target][::-1]
      ans.append(index + 1)
      ans.append(target)

    return ans
