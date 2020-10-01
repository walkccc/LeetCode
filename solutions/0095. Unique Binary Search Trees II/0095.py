class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0:
            return []

        return self.helper(1, n)

    def helper(self, min: int, max: int) -> List[TreeNode]:
        ans = []

        if min > max:
            ans.append(None)
            return ans

        for i in range(min, max + 1):
            leftTree = self.helper(min, i - 1)
            rightTree = self.helper(i + 1, max)
            for left in leftTree:
                for right in rightTree:
                    root = TreeNode(i)
                    root.left = left
                    root.right = right
                    ans.append(root)

        return ans
