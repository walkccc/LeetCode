class Solution:
    def pseudoPalindromicPaths(self, root: TreeNode) -> int:
        def dfs(root: TreeNode, count: List[int]) -> None:
            if not root:
                return
            if not root.left and not root.right:
                count[root.val] += 1
                if all(c % 2 == 0 for c in count) or sum(1 for c in count if c % 2 == 1) == 1:
                    self.ans += 1
                count[root.val] -= 1
                return

            count[root.val] += 1
            dfs(root.left, count)
            count[root.val] -= 1

            count[root.val] += 1
            dfs(root.right, count)
            count[root.val] -= 1

            return count

        self.ans = 0
        dfs(root, [0] * 10)

        return self.ans
