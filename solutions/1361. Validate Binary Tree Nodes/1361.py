from collections import deque

class Solution:
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        root = 0
        childrenNodes = set(leftChild + rightChild)
        for i in range(n):
            if i not in childrenNodes:
                root = i

        visited = set()
        queue = deque([root])

        while queue:
            node = queue.popleft()
            if node in visited:
                return False

            visited.add(node)

            if leftChild[node] != -1:
                queue.append(leftChild[node])
            if rightChild[node] != -1:
                queue.append(rightChild[node])

        return len(visited) == n
