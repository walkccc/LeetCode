class Solution:
  def cloneGraph(self, node: 'Node') -> 'Node':
    if not node:
      return None
    if node in self.map:
      return self.map[node]

    newNode = Node(node.val, [])
    self.map[node] = newNode

    for neighbor in node.neighbors:
      self.map[node].neighbors.append(self.cloneGraph(neighbor))

    return newNode

  map = {}
