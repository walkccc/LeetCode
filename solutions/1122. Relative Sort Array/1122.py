class Solution:
  def relativeSortArray(self, arr1: list[int], arr2: list[int]) -> list[int]:
    ans = []
    count = [0] * 1001

    for a in arr1:
      count[a] += 1

    for a in arr2:
      while count[a] > 0:
        ans.append(a)
        count[a] -= 1

    for num in range(1001):
      for _ in range(count[num]):
        ans.append(num)

    return ans
