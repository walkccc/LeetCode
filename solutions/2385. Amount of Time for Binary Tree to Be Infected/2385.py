class Solution:
  def amountOfTime(self, root: TreeNode | None, start: int) -> int:
    ans = -1
    graph = self._getGraph(root)
    q = collections.deque([start])
    seen = {start}

    while q:
      ans += 1
      for _ in range(len(q)):
        u = q.popleft()
        if u not in graph:
          continue
        for v in graph[u]:
          if v in seen:
            continue
          q.append(v)
          seen.add(v)

    return ans

  def _getGraph(self, root: TreeNode | None) -> dict[int, list[int]]:
    graph = collections.defaultdict(list)
    q = collections.deque([(root, -1)])  # (node, parent)

    while q:
      node, parent = q.popleft()
      if parent != -1:
        graph[parent].append(node.val)
        graph[node.val].append(parent)
      if node.left:
        q.append((node.left, node.val))
      if node.right:
        q.append((node.right, node.val))

    return graph
