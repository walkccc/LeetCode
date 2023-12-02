class Solution:
  def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
    ans = [0] * len(queries)
    count = [0] * (n + 1)
    queryAndIndexes = sorted([(query, i) for i, query in enumerate(queries)])

    logs.sort(key=lambda log: log[1])

    i = 0
    j = 0
    servers = 0

    # For each query, we care about logs[i..j].
    for query, index in queryAndIndexes:
      while j < len(logs) and logs[j][1] <= query:
        count[logs[j][0]] += 1
        if count[logs[j][0]] == 1:
          servers += 1
        j += 1
      while i < len(logs) and logs[i][1] < query - x:
        count[logs[i][0]] -= 1
        if count[logs[i][0]] == 0:
          servers -= 1
        i += 1
      ans[index] = n - servers

    return ans
