class Solution:
  def minimumCost(
      self,
      source: str,
      target: str,
      original: list[str],
      changed: list[str],
      cost: list[int],
  ) -> int:
    ans = 0
    # dist[u][v] := the minimum distance to change ('a' + u) to ('a' + v)
    dist = [[math.inf] * 26 for _ in range(26)]

    for a, b, c in zip(original, changed, cost):
      u = ord(a) - ord('a')
      v = ord(b) - ord('a')
      dist[u][v] = min(dist[u][v], c)

    for k in range(26):
      for i in range(26):
        if dist[i][k] < math.inf:
          for j in range(26):
            if dist[k][j] < math.inf:
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    for s, t in zip(source, target):
      if s == t:
        continue
      u = ord(s) - ord('a')
      v = ord(t) - ord('a')
      if dist[u][v] == math.inf:
        return -1
      ans += dist[u][v]

    return ans
