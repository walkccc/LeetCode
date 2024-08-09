class Solution:
  def minSetSize(self, arr: List[int]) -> int:
    n = len(arr)

    count = collections.Counter(arr).most_common()
    count.sort(key=lambda c: -c[1])

    summ = 0
    for i, c in enumerate(count):
      summ += c[1]
      if summ >= n // 2:
        return i + 1
