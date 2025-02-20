class Solution:
  def countRangeSum(self, nums: list[int], lower: int, upper: int) -> int:
    n = len(nums)
    self.ans = 0
    prefix = list(itertools.accumulate(nums, initial=0))

    self._mergeSort(prefix, 0, n, lower, upper)
    return self.ans

  def _mergeSort(
      self,
      prefix: list[int],
      l: int,
      r: int,
      lower: int,
      upper: int,
  ) -> None:
    if l >= r:
      return

    m = (l + r) // 2
    self._mergeSort(prefix, l, m, lower, upper)
    self._mergeSort(prefix, m + 1, r, lower, upper)
    self._merge(prefix, l, m, r, lower, upper)

  def _merge(
      self,
      prefix: list[int],
      l: int,
      m: int,
      r: int,
      lower: int,
      upper: int,
  ) -> None:
    lo = m + 1  # the first index s.t. prefix[lo] - prefix[i] >= lower
    hi = m + 1  # the first index s.t. prefix[hi] - prefix[i] > upper

    # For each index i in range [l, m], add hi - lo to `ans`.
    for i in range(l, m + 1):
      while lo <= r and prefix[lo] - prefix[i] < lower:
        lo += 1
      while hi <= r and prefix[hi] - prefix[i] <= upper:
        hi += 1
      self.ans += hi - lo

    sorted = [0] * (r - l + 1)
    k = 0  # sorted's index
    i = l  # left's index
    j = m + 1  # right's index

    while i <= m and j <= r:
      if prefix[i] < prefix[j]:
        sorted[k] = prefix[i]
        k += 1
        i += 1
      else:
        sorted[k] = prefix[j]
        k += 1
        j += 1

    # Put the possible remaining left part into the sorted array.
    while i <= m:
      sorted[k] = prefix[i]
      k += 1
      i += 1

    # Put the possible remaining right part into the sorted array.
    while j <= r:
      sorted[k] = prefix[j]
      k += 1
      j += 1

    prefix[l:l + len(sorted)] = sorted
