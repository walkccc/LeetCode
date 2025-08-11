class Solution:
  def minimumCost(
      self,
      source: str,
      target: str,
      original: list[str],
      changed: list[str],
      cost: list[int],
  ) -> int:
    subLengths = set(len(s) for s in original)
    subToId = self._getSubToId(original, changed)
    subCount = len(subToId)
    # dist[u][v] := the minimum distance to change the substring with id u to
    # the substring with id v
    dist = [[math.inf for _ in range(subCount)] for _ in range(subCount)]
    # dp[i] := the minimum cost to change the first i letters of `source` into
    # `target`, leaving the suffix untouched
    dp = [math.inf for _ in range(len(source) + 1)]

    for a, b, c in zip(original, changed, cost):
      u = subToId[a]
      v = subToId[b]
      dist[u][v] = min(dist[u][v], c)

    for k in range(subCount):
      for i in range(subCount):
        if dist[i][k] < math.inf:
          for j in range(subCount):
            if dist[k][j] < math.inf:
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    dp[0] = 0

    for i, (s, t) in enumerate(zip(source, target)):
      if dp[i] == math.inf:
        continue
      if s == t:
        dp[i + 1] = min(dp[i + 1], dp[i])
      for subLength in subLengths:
        if i + subLength > len(source):
          continue
        subSource = source[i:i + subLength]
        subTarget = target[i:i + subLength]
        if subSource not in subToId or subTarget not in subToId:
          continue
        u = subToId[subSource]
        v = subToId[subTarget]
        if dist[u][v] != math.inf:
          dp[i + subLength] = min(dp[i + subLength], dp[i] + dist[u][v])

    return -1 if dp[len(source)] == math.inf else dp[len(source)]

  def _getSubToId(self, original: str, changed: str) -> dict[str, int]:
    subToId = {}
    for s in original + changed:
      if s not in subToId:
        subToId[s] = len(subToId)
    return subToId
