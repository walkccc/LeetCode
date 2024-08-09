class Solution:
  def getStrongest(self, arr: List[int], k: int) -> List[int]:
    arr.sort()

    ans = []
    median = arr[(len(arr) - 1) // 2]
    l = 0
    r = len(arr) - 1

    for _ in range(k):
      if median - arr[l] > arr[r] - median:
        ans.append(arr[l])
        l -= 1
      else:
        ans.append(arr[r])
        r += 1

    return ans
