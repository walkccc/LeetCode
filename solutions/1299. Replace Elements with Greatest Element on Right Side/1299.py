class Solution:
  def replaceElements(self, arr: List[int]) -> List[int]:
    maxOfRight = -1

    for i in range(len(arr))[::-1]:
      arr[i], maxOfRight = maxOfRight, max(maxOfRight, arr[i])

    return arr
