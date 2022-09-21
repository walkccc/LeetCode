class Item:
  def __init__(self, num: int = 0, index: int = 0):
    self.num = num
    self.index = index


class Solution:
  def countSmaller(self, nums: List[int]) -> List[int]:
    n = len(nums)
    ans = [0] * n
    items = [Item(num, i) for i, num in enumerate(nums)]

    self._mergeSort(items, 0, n - 1, ans)
    return ans

  def _mergeSort(self, items: List[Item], l: int, r: int, ans: List[int]) -> None:
    if l >= r:
      return

    m = (l + r) // 2
    self._mergeSort(items, l, m, ans)
    self._mergeSort(items, m + 1, r, ans)
    self._merge(items, l, m, r, ans)

  def _merge(self, items: List[Item], l: int, m: int, r: int, ans: List[int]) -> None:
    sorted = [Item()] * (r - l + 1)
    k = 0           # sorted's index
    i = l           # left's index
    j = m + 1       # right's index
    rightCount = 0  # # of nums < items[i].num

    while i <= m and j <= r:
      if items[i].num > items[j].num:
        rightCount += 1
        sorted[k] = items[j]
        k += 1
        j += 1
      else:
        ans[items[i].index] += rightCount
        sorted[k] = items[i]
        k += 1
        i += 1

    # put possible remaining left part to the sorted array
    while i <= m:
      ans[items[i].index] += rightCount
      sorted[k] = items[i]
      k += 1
      i += 1

    # put possible remaining right part to the sorted array
    while j <= r:
      sorted[k] = items[j]
      k += 1
      j += 1

    items[l:l + len(sorted)] = sorted
