class Solution:
  def xorQueries(self, arr: list[int], queries: list[list[int]]) -> list[int]:
    ans = []
    xors = [0] * (len(arr) + 1)

    for i, a in enumerate(arr):
      xors[i + 1] = xors[i] ^ a

    for left, right in queries:
      ans.append(xors[left] ^ xors[right + 1])

    return ans
