class IndexedQuery:
  def __init__(self, queryIndex: int, query: int):
    self.queryIndex = queryIndex
    self.query = query

  def __iter__(self):
    yield self.queryIndex
    yield self.query


class Solution:
  def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
    ans = [0] * len(queries)
    count = [0] * (n + 1)

    logs.sort(key=lambda log: log[1])

    i = 0
    j = 0
    servers = 0

    # For each query, we care about logs[i..j].
    for queryIndex, query in sorted([IndexedQuery(i, query)
                                     for i, query in enumerate(queries)],
                                    key=lambda iq: iq.query):
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
      ans[queryIndex] = n - servers

    return ans
