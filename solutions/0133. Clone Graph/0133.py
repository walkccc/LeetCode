class Solution:
  def cloneGraph(self, node: 'Node') -> 'Node':
    if not node:
      return None

    q = deque([node])
    map = {node: Node(node.val)}

    while q:
      u = q.popleft()
      for v in u.neighbors:
        if v not in map:
          map[v] = Node(v.val)
          q.append(v)
        map[u].neighbors.append(map[v])

    return map[node]
