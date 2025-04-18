class Solution:
  def countElements(self, arr: list[int]) -> int:
    count = collections.Counter(arr)
    return sum(freq
               for a, freq in count.items()
               if count[a + 1] > 0)
