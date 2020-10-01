class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        ans = 0
        queue = collections.deque([root])

        while queue:
            ans += 1
            for i in range(len(queue)):
                node = queue.popleft()
                if not node.left and not node.right:
                    return ans
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
