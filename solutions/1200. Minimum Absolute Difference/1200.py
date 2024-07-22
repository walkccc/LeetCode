class Solution:
  def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
    ans = []
    min = math.inf

    arr.sort()

    for i in range(len(arr) - 1):
      diff = arr[i + 1] - arr[i]
      if diff < min:
        min = diff
        ans = []
      if diff == min:
        ans.append([arr[i], arr[i + 1]])

    return ans
