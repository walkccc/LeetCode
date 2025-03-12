class Solution:
  def minSetSize(self, arr: list[int]) -> int:
    count = collections.Counter(arr).most_common()
    count.sort(key=lambda x: -x[1])

    summ = 0
    for i, (_, freq) in enumerate(count):
      summ += freq
      if summ >= len(arr) // 2:
        return i + 1
