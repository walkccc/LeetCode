class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        if node in self.lookup:
            return self.lookup[node]

        self.lookup[node] = Node(node.val, [])
        for neighbor in node.neighbors:
            self.lookup[node].neighbors.append(self.cloneGraph(neighbor))

        return self.lookup[node]

    lookup = {}
