class Solution:
  def frequencySort(self, s: str) -> str:
    ans = ""
    bucket = [[] for _ in range(len(s) + 1)]

    for c, freq in Counter(s).items():
      bucket[freq].append(c)

    for freq in range(len(bucket))[::-1]:
      for c in bucket[freq]:
        ans += c * freq

    return ans
