class Solution:
  def sequenceReconstruction(self, org: List[int], seqs: List[List[int]]) -> bool:
    if not seqs:
      return False

    n = len(org)
    graph = [[] for _ in range(n)]
    inDegree = [0] * n

    # build graph
    for seq in seqs:
      if len(seq) == 1 and seq[0] < 1 or seq[0] > n:
        return False
      else:
        for u, v in zip(seq, seq[1:]):
          if u < 1 or u > n or v < 1 or v > n:
            return False
          graph[u - 1].append(v - 1)
          inDegree[v - 1] += 1

    # topology
    q = deque([i for i, d in enumerate(inDegree) if d == 0])
    i = 0  # org's index

    while q:
      if len(q) > 1:
        return False
      u = q.popleft()
      if u != org[i] - 1:
        return False
      i += 1
      for v in graph[u]:
        inDegree[v] -= 1
        if inDegree[v] == 0:
          q.append(v)

    return i == n
