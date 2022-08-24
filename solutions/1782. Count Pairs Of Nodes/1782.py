class Solution:
  def countPairs(self, n: int, edges: List[List[int]], queries: List[int]) -> List[int]:
    ans = [0] * len(queries)

    # count[i] := # of edges of node i
    count = [0] * (n + 1)

    # shared[i][j] := # of edges incident to i or j, where i < j
    shared = [Counter() for _ in range(n + 1)]

    for u, v in edges:
      count[u] += 1
      count[v] += 1
      shared[min(u, v)][max(u, v)] += 1

    sortedCount = sorted(count)

    for k, q in enumerate(queries):
      i = 1
      j = n
      while i < j:
        if sortedCount[i] + sortedCount[j] > q:
          # sortedCount[i] + sortedCount[j] > q
          # sortedCount[i + 1] + sortedCount[j] > q
          # ...
          # sortedCount[j - 1] + sortedCount[j] > q
          # so, there are (j - 1) - i + 1 = j - i pairs > q
          ans[k] += j - i
          j -= 1
        else:
          i += 1
      for i in range(1, n + 1):
        for j, sh in shared[i].items():
          if count[i] + count[j] > q and count[i] + count[j] - sh <= q:
            ans[k] -= 1

    return ans
