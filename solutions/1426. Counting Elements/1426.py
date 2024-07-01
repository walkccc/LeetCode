class Solution:
  def countElements(self, arr: List[int]) -> int:
    count = collections.Counter(arr)
    return sum(freq
               for a, freq in count.items()
               if count[a + 1] > 0)
