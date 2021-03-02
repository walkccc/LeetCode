class Solution:
  def cloneGraph(self, node: 'Node') -> 'Node':
    if not node:
      return None

    q = deque([node])
    map = {}
    map[node] = Node(node.val)

    while q:
      n = q.popleft()
      for neighbor in n.neighbors:
        if neighbor not in map:
          map[neighbor] = Node(neighbor.val)
          q.append(neighbor)
        map[n].neighbors.append(map[neighbor])

    return map[node]
