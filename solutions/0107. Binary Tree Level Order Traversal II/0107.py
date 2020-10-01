class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []

        ans = []

        queue = collections.deque([root])

        while queue:
            currLevel = []
            for _ in range(len(queue)):
                node = queue.popleft()
                currLevel.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ans.insert(0, currLevel)

        return ans
