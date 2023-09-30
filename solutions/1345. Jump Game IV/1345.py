class Solution:
  def minJumps(self, arr: List[int]) -> int:
    n = len(arr)
    # {num: indices}
    graph = collections.defaultdict(list)
    step = 0
    q = collections.deque([0])
    seen = {0}

    for i, a in enumerate(arr):
      graph[a].append(i)

    while q:
      for _ in range(len(q)):
        i = q.popleft()
        if i == n - 1:
          return step
        seen.add(i)
        u = arr[i]
        if i + 1 < n:
          graph[u].append(i + 1)
        if i - 1 >= 0:
          graph[u].append(i - 1)
        for v in graph[u]:
          if v in seen:
            continue
          q.append(v)
        graph[u].clear()
      step += 1
